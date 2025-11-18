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

declare_thirdparty_module(sord)

set(SORD_DIR ${CMAKE_CURRENT_LIST_DIR})

set(MODULE_SRC
    ${SORD_DIR}/src/sord_validate.c
    ${SORD_DIR}/src/sord.c
    ${SORD_DIR}/src/sordi.c
    ${SORD_DIR}/src/syntax.c

    ${SORD_DIR}/include/sord/sord.h

    ${SORD_DIR}/src/sord_config.h
    ${SORD_DIR}/src/sord_internal.h
)

set(MODULE_INCLUDE
    ${SORD_DIR}/include

    ${SERD_INCLUDE_DIRS}
    ${ZIX_INCLUDE_DIRS}
)

set(MODULE_LINK
    serd
    zix
)

set(MODULE_USE_UNITY OFF)
set(MODULE_USE_COVERAGE OFF)

setup_module()

# Export variables
set(SORD_LIBRARIES sord PARENT_SCOPE)
set(SORD_INCLUDE_DIRS ${SORD_DIR}/include PARENT_SCOPE)
