/* Sloth @version 0.x
@link    https://github.com/kabuki-starship/sloth.git
@file    /library/git.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <stdafx.h>
#include "config.h"

#ifndef KABUKI_REFRESH
#define KABUKI_REFRESH

namespace _ {

class Refresh : public Operand {
 public:
  /* Constructs a Sloth Refresh. */
  Refresh();

  /* Script operations. */
  virtual const Op* Star(wchar_t index, Expr* expr);

 private:
  uintptr_t reserved;
};
}       // namespace _
#endif
#endif
