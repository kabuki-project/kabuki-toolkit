/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    ~/kabuki/crabs/socket.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <stdafx.h>

#if SEAM >= SEAM_0_0_1

#ifndef INCLUDED_CRABS_ALIGN
#define INCLUDED_CRABS_ALIGN
// Dependencies:
#include "config.h"
// End dependencies.

namespace _ {

/* Compute the next highest power of 2. */
DLL inline uint32_t AlignPowerOf2(uint32_t value);

/* Compute the next highest power of 2. */
DLL inline int32_t AlignPowerOf2(int32_t value);

/* Aligns the given buffer pointer up to a cache line boundary (64 bytes). */
DLL inline uintptr_t* AlignUpCacheLine(uintptr_t* buffer);

/* Aligns the given pointer up to a word boandard. */
DLL char* AlignUpPointerWord(char* pointer);

/* Aligns the given pointer up to a word boandard. */
DLL const char* AlignUpPointerWord(const char* pointer);

/* Aligns the pointer down to a word boundary. */
DLL char* AlignDownPointerWord(char* pointer);

/* Aligns the pointer down to a word boundary. */
DLL const char* AlignDownPointerWord(const char* pointer);

/* Aligns up the pointer to the given boundary_bit_count. */
DLL inline uintptr_t* AlignUp(uintptr_t* pointer,
                                 uintptr_t boundary_bit_count);

/* Aligns the given value up to an 8-byte boundary. */
DLL inline int8_t AlignUp(int8_t value);

/* Aligns the given value up to an 16-byte boundary. */
DLL int16_t AlignUp(int16_t value);

/* Aligns the given value up to an 32-byte boundary. */
DLL inline int32_t AlignUp(int32_t value);

/* Aligns the given value up to an 64-byte boundary. */
DLL inline int64_t AlignUp(int64_t value);

}  // namespace _
#endif  //< INCLUDED_CRABS_ALIGN

#endif  //< #if SEAM >= SEAM_0_0_1
