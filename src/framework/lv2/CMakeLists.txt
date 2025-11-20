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

declare_module(muse_lv2)
set(MODULE_ALIAS muse::lv2)

include(cmake/SetupLilv.cmake)
include(cmake/SetupSerd.cmake)
include(cmake/SetupSord.cmake)
include(cmake/SetupSratom.cmake)
include(cmake/SetupZix.cmake)

set(MODULE_QRC lv2.qrc)

set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
    ${CMAKE_CURRENT_LIST_DIR}/lv2module.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/lv2instancesrepository.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/fx/lv2fxprocessor.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/fx/lv2fxresolver.cpp

    ${CMAKE_CURRENT_LIST_DIR}/ilv2instancesrepository.h
    ${CMAKE_CURRENT_LIST_DIR}/ilv2plugininstance.h
    ${CMAKE_CURRENT_LIST_DIR}/ilv2world.h
    ${CMAKE_CURRENT_LIST_DIR}/lv2module.h
    ${CMAKE_CURRENT_LIST_DIR}/lv2types.h
    ${CMAKE_CURRENT_LIST_DIR}/internal/lv2instancesrepository.h
    ${CMAKE_CURRENT_LIST_DIR}/internal/lv2plugininstance.h
    ${CMAKE_CURRENT_LIST_DIR}/internal/lv2world.h
    ${CMAKE_CURRENT_LIST_DIR}/internal/fx/lv2fxprocessor.h
    ${CMAKE_CURRENT_LIST_DIR}/internal/fx/lv2fxresolver.h
    )

set(MODULE_LINK
    lilv
    )

if (QT_SUPPORT)
    list(APPEND MODULE_LINK Qt::Qml Qt::Widgets)
endif()

setup_module()

target_no_warning(${MODULE} -Wno-deprecated-declarations)
