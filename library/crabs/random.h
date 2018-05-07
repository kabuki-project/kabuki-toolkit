/** Kabuki Toolkit
    @version 0.x
    @file    ~/libraries/crabs/random.hf
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2014-2017-2018 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once
#include <stdafx.h>

#ifndef HEADER_FOR_CRABS_RANDOM
#define HEADER_FOR_CRABS_RANDOM

#include "config.h"

#if MAJOR_SEAM > 1 || MAJOR_SEAM == 1 && MINOR_SEAM >= 1

namespace _ {
inline uint64_t GetRandomUInt64 () {
    std::random_device rd;
    std::mt19937_64 eng (rd ());
    std::uniform_int_distribution<uint64_t> distr;
    return distr (eng);
}

inline int64_t GetRandomInt64 () {
    return (int64_t)GetRandomUInt64 ();
}

}       //< namespace _
#endif  //< #if MAJOR_SEAM > 1 || MAJOR_SEAM == 1 && MINOR_SEAM >= 1
#endif  //< HEADER_FOR_CRABS_RANDOM
