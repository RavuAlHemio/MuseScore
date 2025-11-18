# SPDX-License-Identifier: GPL-3.0-only
# MuseScore-CLA-applies
#
# MuseScore
# Music Composition & Notation
#
# Copyright (C) 2025 MuseScore Limited and others
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

declare_thirdparty_module(lilv)

set(LILV_DIR ${CMAKE_CURRENT_LIST_DIR})

set(MODULE_SRC
    ${LILV_DIR}/src/collections.c
    ${LILV_DIR}/src/dylib.c
    ${LILV_DIR}/src/instance.c
    ${LILV_DIR}/src/lib.c
    ${LILV_DIR}/src/load_skimmer.c
    ${LILV_DIR}/src/node_hash.c
    ${LILV_DIR}/src/node_skimmer.c
    ${LILV_DIR}/src/node.c
    ${LILV_DIR}/src/plugin.c
    ${LILV_DIR}/src/pluginclass.c
    ${LILV_DIR}/src/port.c
    ${LILV_DIR}/src/query.c
    ${LILV_DIR}/src/scalepoint.c
    ${LILV_DIR}/src/state.c
    ${LILV_DIR}/src/string_util.c
    ${LILV_DIR}/src/syntax_skimmer.c
    ${LILV_DIR}/src/sys_util.c
    ${LILV_DIR}/src/type_skimmer.c
    ${LILV_DIR}/src/ui.c
    ${LILV_DIR}/src/uris.c
    ${LILV_DIR}/src/world.c

    ${LILV_DIR}/include/lilv/lilv.h

    ${LILV_DIR}/src/dylib.h
    ${LILV_DIR}/src/lilv_config.h
    ${LILV_DIR}/src/lilv_internal.h
    ${LILV_DIR}/src/load_skimmer.h
    ${LILV_DIR}/src/log.h
    ${LILV_DIR}/src/node_hash.h
    ${LILV_DIR}/src/node_skimmer.h
    ${LILV_DIR}/src/query.h
    ${LILV_DIR}/src/string_util.h
    ${LILV_DIR}/src/syntax_skimmer.h
    ${LILV_DIR}/src/sys_util.h
    ${LILV_DIR}/src/type_skimmer.h
    ${LILV_DIR}/src/uris.h
)

set(MODULE_INCLUDE
    ${LILV_DIR}/include

    ${SERD_INCLUDE_DIRS}
    ${SORD_INCLUDE_DIRS}
    ${ZIX_INCLUDE_DIRS}
)

set(MODULE_LINK
    serd
    sord
    sratom
    zix
)

set(MODULE_USE_UNITY OFF)
set(MODULE_USE_COVERAGE OFF)

setup_module()

# Export variables
set(LILV_LIBRARIES lilv PARENT_SCOPE)
set(LILV_INCLUDE_DIRS ${LILV_DIR}/include PARENT_SCOPE)
