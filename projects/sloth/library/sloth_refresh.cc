/* Sloth
@link    https://github.com/kabuki-starship/sloth.git
@file    /library/sloth_git.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <stdafx.h>
#if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
#include "refresh.h"

namespace _ {

Refresh::Refresh() : reserved(0) {}

const Op* Refresh::Star(wchar_t index, Expr* expr) {
  void* args[1];
  switch (index) {
    case '?': {
      static const Op kThis = {"Sloth", OpFirst(' '), OpLast(' '), "#CodeSloth",
                               '}',     ';',          ' ',         false,
                               nullptr, nullptr,      nullptr};
      return &kThis;
    }
    case ' ': {
      static const Op kClone = {
          "clone", Params<1, TKN, 4>(),
          0,       "Push Operation that occurs upon updating the toolkit.",
          '}',     ';',
          ' ',     false,
          0,       0,
          0};
      if (!expr) return &kClone;
      CH1 buffer[256];
      Print(buffer, buffer + 255, "git clone ");
      if (!ExprArgs(expr, kClone, Args(args, &buffer[10]))) return expr->result;
      system(&buffer[9]);
      return 0;
    }
  }
  return nullptr;
}

}       //< namespace _
#endif
