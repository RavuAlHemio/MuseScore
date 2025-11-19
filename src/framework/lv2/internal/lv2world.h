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

#ifndef MUSE_LV2_LV2WORLD_H
#define MUSE_LV2_LV2WORLD_H

#include "ilv2world.h"

namespace muse::lv2 {
class Lv2World : public ILv2World
{
public:
    Lv2World();

    bool initSucceeded() const { return m_lw != nullptr; }

private:
    std::shared_ptr<Lilv::World> m_lw;
};
}

#endif // MUSE_LV2_LV2WORLD_H
