/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore Limited and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "lv2instancesrepository.h"

using namespace muse;
using namespace muse::lv2;

void Lv2InstancesRepository::init()
{
    ONLY_MAIN_THREAD(threadSecurer);
}

void Lv2InstancesRepository::deInit()
{
    for (auto& pair : m_instances) {
        pair.second.reset();
    }
}

bool Lv2InstancesRepository::exists(const muse::audio::AudioResourceId& resourceId) const
{
    ONLY_AUDIO_THREAD(threadSecurer);

    std::lock_guard lock(m_mutex);

    return knownPlugins()->exists(resourceId);
}

PluginInstancePtr Lv2InstancesRepository::pluginInstance(const muse::audio::AudioResourceId& resourceId) const
{
    ONLY_AUDIO_OR_MAIN_THREAD(threadSecurer);

    std::lock_guard lock(m_mutex);

    auto search = m_instances.find(resourceId);

    if (search != m_instances.end()) {
        return search->second;
    }

    return nullptr;
}

void Lv2InstancesRepository::addNewPluginInstance(const muse::audio::AudioResourceId& resourceId)
{
    ONLY_MAIN_THREAD(threadSecurer);

    std::lock_guard lock(m_mutex);

    auto search = m_instances.find(resourceId);
    if (search != m_instances.end()) {
        return;
    }

    PluginInstancePtr module = instantiatePlugin(knownPlugins()->pluginPath(resourceId));
    if (!module) {
        return;
    }

    m_instances.emplace(resourceId, std::move(module));
}

void Lv2InstancesRepository::removePluginInstance(const muse::audio::AudioResourceId& resourceId)
{
    ONLY_MAIN_THREAD(threadSecurer);

    std::lock_guard lock(m_mutex);

    auto search = m_instances.find(resourceId);
    if (search == m_instances.end()) {
        return;
    }

    m_instances.erase(search);
}

muse::audio::AudioResourceMetaList Lv2InstancesRepository::instrumentModulesMeta() const
{
    ONLY_AUDIO_THREAD(threadSecurer);

    std::lock_guard lock(m_mutex);

    return modulesMetaList(audioplugins::AudioPluginType::Instrument);
}

muse::audio::AudioResourceMetaList Lv2InstancesRepository::fxModulesMeta() const
{
    ONLY_AUDIO_THREAD(threadSecurer);

    std::lock_guard lock(m_mutex);

    return modulesMetaList(audioplugins::AudioPluginType::Fx);
}

void Lv2InstancesRepository::refresh()
{
}

muse::audio::AudioResourceMetaList Lv2InstancesRepository::modulesMetaList(const audioplugins::AudioPluginType& type) const
{
    auto infoAccepted = [type](const audioplugins::AudioPluginInfo& info) {
        return info.type == type && info.meta.type == muse::audio::AudioResourceType::Lv2Plugin && info.enabled;
    };

    std::vector<audioplugins::AudioPluginInfo> infoList = knownPlugins()->pluginInfoList(infoAccepted);
    muse::audio::AudioResourceMetaList result;

    for (const audioplugins::AudioPluginInfo& info : infoList) {
        result.push_back(info.meta);
    }

    return result;
}
