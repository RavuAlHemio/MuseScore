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

if (MUE_COMPILE_USE_SYSTEM_SRATOM)
    find_package(sratom)

    if (SRATOM_FOUND)
        message(STATUS "Found sord: ${SRATOM_VERSION_STRING}")
    else()
        message(WARNING "Set MUE_COMPILE_USE_SYSTEM_SRATOM=ON, but system sratom not found, built-in will be used")
    endif()
endif()

if (NOT SRATOM_FOUND)
    # sets SRATOM_LIBRARIES and SRATOM_LIBRARIES
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../thirdparty/sratom-0.6.20 sratom)
endif()
