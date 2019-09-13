/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/t_relationahip.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_WHO_1
#ifndef kabuki.toolkit_WHO_RELATIONSHIP
#define kabuki.toolkit_WHO_RELATIONSHIP

#include "t_entity.h"

namespace _ {

/* A relationship node between . */
class TRelationship {
 public:
  /* Default constructor. */
  TRelationship();

  /* Prints this object to a expression. */
   Printer& Print (Printer& o) {

 private:
  const TStrand<>& type_;
  Entity *a, *b;
};
}       // namespace _
#endif  //< kabuki.toolkit_WHO_RELATIONSHIP
#endif  //< #if SEAM >= kabuki.toolkit_WHO_1