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
#pragma once

#include "global/async/notification.h"

#include "audio/common/audiotypes.h"

namespace muse::lv2 {
class ILv2PluginInstance
{
public:
    virtual ~ILv2PluginInstance() = default;

    virtual const muse::audio::AudioResourceId& resourceId() const = 0;
    virtual const std::string& name() const = 0;

    virtual bool isLoaded() const = 0;
    virtual async::Notification loadingCompleted() const = 0;

    virtual void updatePluginConfig(const muse::audio::AudioUnitConfig& config) = 0;
    virtual void refreshConfig() = 0;
    virtual async::Channel<muse::audio::AudioUnitConfig> pluginSettingsChanged() const = 0;

    virtual void setSampleRate(muse::audio::sample_rate_t newRate) = 0;
    virtual void process(float *buffer, unsigned int sampleCount) = 0;
};
}
