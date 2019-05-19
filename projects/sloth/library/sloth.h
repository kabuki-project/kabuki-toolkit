/* Sloth
@link    https://github.com/kabuki-starship/sloth.git
@file    /library/sloth.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <stdafx.h>
#if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
#include "config.h"

#ifndef KABUKI_SLOTH
#define KABUKI_SLOTH

namespace _ {

class Sloth : public Operand {
 public:
  /* Constructs a Sloth. */
  Sloth();

  /* Script operations. */
  virtual const Op* Star(wchar_t index, Expr* expr);

 private:
  uintptr_t reserved;
};
}  // namespace _
#endif
#endif
