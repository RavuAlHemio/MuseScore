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

#include "lv2fxresolver.h"

#include "lv2fxprocessor.h"

#include "log.h"

using namespace muse::lv2;
using namespace muse::audio;
using namespace muse::audio::fx;

AudioResourceMetaList Lv2FxResolver::resolveResources() const
{
    return pluginModulesRepo()->fxModulesMeta();
}

void Lv2FxResolver::refresh()
{
    pluginModulesRepo()->refresh();
}

void Lv2FxResolver::clearAllFx()
{
    instancesRegister()->unregisterAllFx();

    AbstractFxResolver::clearAllFx();
}

IFxProcessorPtr Lv2FxResolver::createMasterFx(const AudioFxParams& fxParams, const audio::OutputSpec& outputSpec) const
{
    if (!pluginModulesRepo()->exists(fxParams.resourceMeta.id)) {
        return nullptr;
    }

    IVstPluginInstancePtr pluginPtr = instancesRegister()->makeAndRegisterMasterFxPlugin(fxParams.resourceMeta.id, fxParams.chainOrder);

    std::shared_ptr<Lv2FxProcessor> fx = std::make_shared<Lv2FxProcessor>(std::move(pluginPtr), fxParams);
    fx->init(outputSpec);

    return fx;
}

IFxProcessorPtr Lv2FxResolver::createTrackFx(const TrackId trackId, const AudioFxParams& fxParams,
                                             const audio::OutputSpec& outputSpec) const
{
    if (!pluginModulesRepo()->exists(fxParams.resourceMeta.id)) {
        LOGE() << "Unable to create VST plugin"
               << ", pluginId: " << fxParams.resourceMeta.id
               << ", trackId: " << trackId;
        return nullptr;
    }

    IVstPluginInstancePtr pluginPtr = instancesRegister()->makeAndRegisterFxPlugin(fxParams.resourceMeta.id, trackId, fxParams.chainOrder);

    std::shared_ptr<VstFxProcessor> fx = std::make_shared<VstFxProcessor>(std::move(pluginPtr), fxParams);
    fx->init(outputSpec);

    return fx;
}

void Lv2FxResolver::removeMasterFx(const AudioResourceId& resoureId, AudioFxChainOrder chainOrder)
{
    instancesRegister()->unregisterMasterFxPlugin(resoureId, chainOrder);
}

void Lv2FxResolver::removeTrackFx(const TrackId trackId, const AudioResourceId& resoureId, AudioFxChainOrder chainOrder)
{
    instancesRegister()->unregisterFxPlugin(resoureId, trackId, chainOrder);
}
