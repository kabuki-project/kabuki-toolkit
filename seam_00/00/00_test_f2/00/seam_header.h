/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    ~/kabuki/f2/f2_test.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once

#include <pch.h>

#if SEAM == SEAM_00_00_00__01_00
#include <kabuki/f2/global.h>

#include "console.h"

namespace _ {

template <typename UI>
static void PrinttoSDebug(UI value) {
  enum { kSize = sizeof(UI) * 8 };

  const char* debug_table =
      sizeof(UI) == 8
          ? "\n    "
            "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
            "\n    "
            "6666555555555544444444443333333333222222222211111111110000000000"
            "\n    "
            "3210987654321098765432109876543210987654321098765432109876543210"
            "\n    "
            "|  |  |  |   |  |  |   |  |  |   |  |  |   |  |  |   |  |  |   |"
            "\n    "
            "2  1  1  1   1  1  1   1  1  1   1  0  0   0  0  0   0  0  0   0"
            "\n    "
            "0  9  8  7   6  5  4   3  2  1   0  9  8   7  6  5   4  3  2   1"
          : "\n    bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
            "\n    33222222222211111111110000000000"
            "\n    10987654321098765432109876543210"
            "\n    ||  |  |   |  |  |   |  |  |   |"
            "\n    |1  0  0   0  0  0   0  0  0   0"
            "\n    |0  9  8   7  6  5   4  3  2   1";

  PrintIndent(4);
  PrintBinary<UI>(value);
  Printf(debug_table);
}

static char* buffer_begin = 0;

template <typename UI>
static void PrintPrinted(char* cursor) {
  static const char* format = (sizeof(UI) == 8) ? FORMAT_UI8 : "%i";

  Printf("\n    Printed \"%s\" leaving value:\"%s\"", buffer_begin, cursor);
  char* start = cursor;
  while (*cursor++)
    ;
  Print(':');
  Printf(format, cursor - start);
}

}  // namespace _

#define PRINT(item) Print(item)
#define PRINTF(format, ...) Printf(format, __VA_ARGS__)
#define PRINT_PRINTED PrintPrinted(buffer, buffer, value);

#define PRINT_BINARY \
  PrintIndent(4);    \
  PrintBinary(value);
#define PRINT_BINARY_TABLE PrintBinaryTable(value);
#define BEGIN_ITOS_ALGORITHM                            \
  buffer_begin = cursor;                                \
  for (int32_t i = 0; i < 10; ++i) *(cursor + i) = 'x'; \
  *(cursor + 21) = 0;                                   \
  char* buffer = cursor;                                \
  char buffer[256];                                     \
  sprintf_s(buffer, 256, "%u", value);                  \
  Printf("Expecting %s:%u", buffer, (uint)strlen(buffer));
#else
#define PRINT(item)
#define PRINTF(x, ...)
#define PRINT_PRINTED ;
#define BEGIN_ITOS_ALGORITHM
#endif