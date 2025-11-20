/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2025 MuseScore Limited and others
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

#ifndef MUSE_LV2_LV2INSTANCESREPOSITORY_H
#define MUSE_LV2_LV2INSTANCESREPOSITORY_H

#include <unordered_map>
#include <mutex>

#include "modularity/ioc.h"
#include "audioplugins/iknownaudiopluginsregister.h"
#include "audio/common/iaudiothreadsecurer.h"

#include "audioplugins/audiopluginstypes.h"

#include "ilv2instancesrepository.h"
#include "ilv2world.h"
#include "lv2types.h"

namespace muse::lv2 {
class Lv2InstancesRepository : public ILv2InstancesRepository
{
    INJECT(audioplugins::IKnownAudioPluginsRegister, knownPlugins)
    INJECT(ILv2World, lv2World)
    INJECT_STATIC(muse::audio::IAudioThreadSecurer, threadSecurer)

public:
    Lv2InstancesRepository() = default;

    void init();
    void deInit();

    bool exists(const muse::audio::AudioResourceId& resourceId) const override;
    PluginInstancePtr pluginInstance(const muse::audio::AudioResourceId& resourceId) const override;
    void addNewPluginInstance(const muse::audio::AudioResourceId& resourceId) override;
    void removePluginInstance(const muse::audio::AudioResourceId& resourceId) override;

    audio::AudioResourceMetaList instrumentModulesMeta() const override;
    audio::AudioResourceMetaList fxModulesMeta() const override;
    void refresh() override;

private:
    audio::AudioResourceMetaList modulesMetaList(const audioplugins::AudioPluginType& type) const;

    mutable std::mutex m_mutex;
    mutable std::unordered_map<audio::AudioResourceId, PluginInstancePtr> m_instances;
};
}

#endif // MUSE_LV2_LV2INSTANCESREPOSITORY_H
