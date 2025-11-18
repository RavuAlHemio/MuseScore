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

if (MUE_COMPILE_USE_SYSTEM_ZIX)
    find_package(zix)

    if (ZIX_FOUND)
        message(STATUS "Found zix: ${ZIX_VERSION_STRING}")
    else()
        message(WARNING "Set MUE_COMPILE_USE_SYSTEM_ZIX=ON, but system zix not found, built-in will be used")
    endif()
endif()

if (NOT ZIX_FOUND)
    # sets ZIX_LIBRARIES and ZIX_LIBRARIES
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../thirdparty/zix-0.8.0 zix)
endif()
