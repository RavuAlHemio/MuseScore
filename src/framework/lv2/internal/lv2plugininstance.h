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

#ifndef MUSE_LV2_LV2PLUGININSTANCE_H
#define MUSE_LV2_LV2PLUGININSTANCE_H

#include <mutex>
#include <atomic>

#include "../ilv2plugininstance.h"

#include "modularity/ioc.h"
#include "async/asyncable.h"
#include "async/notification.h"
#include "async/channel.h"
#include "audio/common/iaudiothreadsecurer.h"
#include "audio/common/audiotypes.h"

namespace muse::lv2 {
class Lv2PluginProvider;
class Lv2PluginInstance : public ILv2PluginInstance, public async::Asyncable
{
    muse::GlobalInject<muse::audio::IAudioThreadSecurer> threadSecurer;

public:
    Lv2PluginInstance(const muse::audio::AudioResourceId& resourceId);
    ~Lv2PluginInstance() override;

    const muse::audio::AudioResourceId& resourceId() const override;
    const std::string& name() const override;

    bool isAbleForInput() const;

    void updatePluginConfig(const muse::audio::AudioUnitConfig& config) override;
    void refreshConfig() override;

    void load();

    bool isValid() const;
    bool isLoaded() const override;

    async::Notification loadingCompleted() const override;

    async::Channel<muse::audio::AudioUnitConfig> pluginSettingsChanged() const override;

    void setSampleRate(muse::audio::sample_rate_t newRate) override;

private:
    muse::audio::AudioResourceId m_resourceId;

    std::shared_ptr<Lilv::Instance> m_instance = nullptr;
    mutable async::Channel<muse::audio::AudioUnitConfig> m_pluginSettingsChanges;

    std::atomic_bool m_isLoaded = false;
    async::Notification m_loadingCompleted;

    mutable std::mutex m_mutex;
};
}

#endif // MUSE_LV2_LV2PLUGININSTANCE_H
