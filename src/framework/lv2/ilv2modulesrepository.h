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

#ifndef MUSE_LV2_ILV2MODULESREPOSITORY_H
#define MUSE_LV2_ILV2MODULESREPOSITORY_H

#include <lilv/lilv.h>

#include "modularity/imoduleinterface.h"
#include "audio/common/audiotypes.h"

#include "lv2types.h"

namespace muse::lv2 {
class ILv2ModulesRepository : MODULE_EXPORT_INTERFACE
{
    INTERFACE_ID(ILv2ModulesRepository)

public:
    virtual ~ILv2ModulesRepository() = default;

    virtual bool exists(const muse::audio::AudioResourceId& resourceId) const = 0;
    virtual PluginModulePtr pluginModule(const muse::audio::AudioResourceId& resourceId) const = 0;
    virtual void addPluginModule(const muse::audio::AudioResourceId& resourceId) = 0;
    virtual void removePluginModule(const muse::audio::AudioResourceId& resourceId) = 0;
    virtual muse::audio::AudioResourceMetaList instrumentModulesMeta() const = 0;
    virtual muse::audio::AudioResourceMetaList fxModulesMeta() const = 0;
    virtual void refresh() = 0;
};
}

#endif // MUSE_LV2_ILV2MODULESREPOSITORY_H
