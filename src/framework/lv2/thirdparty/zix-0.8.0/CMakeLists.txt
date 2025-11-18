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

declare_thirdparty_module(zix)

set(ZIX_DIR ${CMAKE_CURRENT_LIST_DIR})

set(MODULE_SRC
    ${ZIX_DIR}/src/allocator.c
    ${ZIX_DIR}/src/btree.c
    ${ZIX_DIR}/src/bump_allocator.c
    ${ZIX_DIR}/src/digest.c
    ${ZIX_DIR}/src/errno_status.c
    ${ZIX_DIR}/src/filesystem.c
    ${ZIX_DIR}/src/hash.c
    ${ZIX_DIR}/src/path.c
    ${ZIX_DIR}/src/ring.c
    ${ZIX_DIR}/src/status.c
    ${ZIX_DIR}/src/string_view.c
    ${ZIX_DIR}/src/system.c
    ${ZIX_DIR}/src/tree.c

    ${ZIX_DIR}/include/zix/allocator.h
    ${ZIX_DIR}/include/zix/attributes.h
    ${ZIX_DIR}/include/zix/btree.h
    ${ZIX_DIR}/include/zix/bump_allocator.h
    ${ZIX_DIR}/include/zix/digest.h
    ${ZIX_DIR}/include/zix/environment.h
    ${ZIX_DIR}/include/zix/filesystem.h
    ${ZIX_DIR}/include/zix/hash.h
    ${ZIX_DIR}/include/zix/path.h
    ${ZIX_DIR}/include/zix/ring.h
    ${ZIX_DIR}/include/zix/sem.h
    ${ZIX_DIR}/include/zix/status.h
    ${ZIX_DIR}/include/zix/string_view.h
    ${ZIX_DIR}/include/zix/thread.h
    ${ZIX_DIR}/include/zix/tree.h
    ${ZIX_DIR}/include/zix/warnings.h
    ${ZIX_DIR}/include/zix/zix.h

    ${ZIX_DIR}/src/errno_status.h
    ${ZIX_DIR}/src/index_range.h
    ${ZIX_DIR}/src/path_iter.h
    ${ZIX_DIR}/src/qualifiers.h
    ${ZIX_DIR}/src/system.h
    ${ZIX_DIR}/src/zix_config.h
)

set(MODULE_INCLUDE
    ${ZIX_DIR}/include
)

set(MODULE_USE_UNITY OFF)
set(MODULE_USE_COVERAGE OFF)

setup_module()

# Export variables
set(ZIX_LIBRARIES zix PARENT_SCOPE)
set(ZIX_INCLUDE_DIRS ${ZIX_DIR}/include PARENT_SCOPE)
