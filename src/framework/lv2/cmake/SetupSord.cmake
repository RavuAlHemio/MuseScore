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

if (MUE_COMPILE_USE_SYSTEM_SORD)
    find_package(sord)

    if (SORD_FOUND)
        message(STATUS "Found sord: ${SORD_VERSION_STRING}")
    else()
        message(WARNING "Set MUE_COMPILE_USE_SYSTEM_SORD=ON, but system sord not found, built-in will be used")
    endif()
endif()

if (NOT SORD_FOUND)
    # sets SORD_LIBRARIES and SORD_LIBRARIES
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../thirdparty/sord-0.16.20 sord)
endif()
