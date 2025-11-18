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

declare_thirdparty_module(serd)

set(SERD_DIR ${CMAKE_CURRENT_LIST_DIR})

set(MODULE_SRC
    ${SERD_DIR}/src/base64.c
    ${SERD_DIR}/src/byte_source.c
    ${SERD_DIR}/src/env.c
    ${SERD_DIR}/src/n3.c
    ${SERD_DIR}/src/node.c
    ${SERD_DIR}/src/reader.c
    ${SERD_DIR}/src/serdi.c
    ${SERD_DIR}/src/string.c
    ${SERD_DIR}/src/system.c
    ${SERD_DIR}/src/uri.c
    ${SERD_DIR}/src/writer.c


    ${SERD_DIR}/include/serd/serd.h

    ${SERD_DIR}/src/attributes.h
    ${SERD_DIR}/src/base64.h
    ${SERD_DIR}/src/byte_sink.h
    ${SERD_DIR}/src/byte_source.h
    ${SERD_DIR}/src/reader.h
    ${SERD_DIR}/src/serd_config.h
    ${SERD_DIR}/src/serd_internal.h
    ${SERD_DIR}/src/stack.h
    ${SERD_DIR}/src/string_utils.h
    ${SERD_DIR}/src/system.h
    ${SERD_DIR}/src/try.h
    ${SERD_DIR}/src/uri_utils.h
    ${SERD_DIR}/src/warnings.h
)

message(STATUS "serd sources: ${MODULE_SRC}")

set(MODULE_INCLUDE
    ${SERD_DIR}/include
)

set(MODULE_USE_UNITY OFF)
set(MODULE_USE_COVERAGE OFF)

setup_module()

# Export variables
set(SERD_LIBRARIES serd PARENT_SCOPE)
set(SERD_INCLUDE_DIRS ${SERD_DIR}/include PARENT_SCOPE)
