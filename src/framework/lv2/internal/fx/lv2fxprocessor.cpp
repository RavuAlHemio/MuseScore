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

#include "lv2fxprocessor.h"

using namespace muse;
using namespace muse::lv2;
using namespace muse::audio;
using namespace muse::audioplugins;

Lv2FxProcessor::Lv2FxProcessor(std::shared_ptr<ILv2PluginInstance>&& instance, const AudioFxParams& params)
    : m_pluginPtr(instance),
    m_params(params)
{
}

void Lv2FxProcessor::init(const audio::OutputSpec& spec)
{
    IF_ASSERT_FAILED(spec.isValid()) {
        return;
    }

    m_outputSpec = spec;

    auto onPluginLoaded = [this]() {
        m_pluginPtr->updatePluginConfig(m_params.configuration);
        m_pluginPtr->setSampleRate(m_outputSpec.sampleRate);
        m_inited = true;
    };

    if (m_pluginPtr->isLoaded()) {
        onPluginLoaded();
    } else {
        m_pluginPtr->loadingCompleted().onNotify(this, onPluginLoaded);
    }

    m_pluginPtr->pluginSettingsChanged().onReceive(this, [this](const muse::audio::AudioUnitConfig& newConfig) {
        if (m_params.configuration == newConfig) {
            return;
        }

        m_params.configuration = newConfig;
        m_paramsChanges.send(m_params);
    });
}

AudioFxType Lv2FxProcessor::type() const
{
    return muse::audio::AudioFxType::Lv2Fx;
}

const AudioFxParams& Lv2FxProcessor::params() const
{
    return m_params;
}

async::Channel<AudioFxParams> Lv2FxProcessor::paramsChanged() const
{
    return m_paramsChanges;
}

void Lv2FxProcessor::setOutputSpec(const audio::OutputSpec& spec)
{
    m_outputSpec = spec;
    m_pluginPtr->setSampleRate(spec.sampleRate);
}

bool Lv2FxProcessor::active() const
{
    return m_params.active;
}

void Lv2FxProcessor::setActive(bool active)
{
    m_params.active = active;
}

void Lv2FxProcessor::process(float* buffer, unsigned int sampleCount)
{
    if (!buffer || !m_inited) {
        return;
    }

    m_pluginPtr->process(buffer, sampleCount);
}
