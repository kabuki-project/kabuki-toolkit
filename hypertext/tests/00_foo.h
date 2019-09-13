/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /pro/tests/00_foo.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>

#if SEAM == HYPERTEXT_FOO
#include <script2/module_debug.inl>
#else
#include <script2/module_release.inl>
#endif

using namespace _;

namespace kabuki {
namespace toolkit {
namespace hypertext {
inline const CH1* Foo(CH1* seam_log, CH1* seam_end, const CH1* args) {
#if SEAM >= kabuki.toolkit_PRO_0
  TEST_BEGIN;

  D_COUT("Testing Foo Fun.");

#endif
  return 0;
}
}  // namespace hypertext
}  // namespace toolkit
}  // namespace kabuki