/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    ~/kabuki/f2/vk.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#if SEAM >= SEAM_00_00_00__01
#ifndef INCLUDED_KABUKI_F2_VK
#define INCLUDED_KABUKI_F2_VK 1

namespace _ {

/* Gets the names of the KeyId. */
inline const char* KeyIdName();

/* Gets the array of KeyId offsets. */
inline const int16_t* KeyIdOffset();

/* Gets the array of KeyId order. */
inline const uint8_t* KeyIdOrder();

/* Gets the name from the VK code. */
inline const char* KeyIdNameFromCode(int code);

/* Gets the VK code from the name of the key. */
inline int KeyIdCodeFromName(const char* name);

/* Convert a key id to an HID code.
@return Pointer to the a LUT.   */
const uint8_t* KeyboardNativeToHID();

/* Convert an HID code to a key id.
@return Pointer to the a LUT. */
const uint8_t* KeyboardHIDToNative();

typedef int VKCode;
enum {
  kVKA = 4,
  kVKB = 5,
  kVKC = 6,
  kVKD = 7,
  kVKE = 8,
  kVKF = 9,
  kVKG = 10,
  kVKH = 11,
  kVKI = 12,
  kVKJ = 13,
  kVKK = 14,
  kVKL = 15,
  kVKM = 16,
  kVKN = 17,
  kVKO = 18,
  kVKP = 19,
  kVKQ = 20,
  kVKR = 21,
  kVKS = 22,
  kVKT = 23,
  kVKU = 24,
  kVKV = 25,
  kVKW = 26,
  kVKX = 27,
  kVKY = 28,
  kVKZ = 29,
  kVK1 = 30,
  kVK2 = 31,
  kVK3 = 32,
  kVK4 = 33,
  kVK5 = 34,
  kVK6 = 35,
  kVK7 = 36,
  kVK8 = 37,
  kVK9 = 38,
  kVK0 = 39,
  kVKEnter = 40,
  kVKEscape = 41,
  kVKDelete = 42,
  kVKTab = 43,
  kVKSpace = 44,
  kVKMinus = 45,
  kVKEquals = 46,
  kVKLeftBracket = 47,
  kVKRightBracket = 48,
  kVKBackslash = 49,
  kVKSemicolon = 51,
  kVKQuote = 52,
  kVKGrave = 53,
  kVKComma = 54,
  kVKPeriod = 55,
  kVKSlash = 56,
  kVKCapsLock = 57,
  kVKF1 = 58,
  kVKF2 = 59,
  kVKF3 = 60,
  kVKF4 = 61,
  kVKF5 = 62,
  kVKF6 = 63,
  kVKF7 = 64,
  kVKF8 = 65,
  kVKF9 = 66,
  kVKF10 = 67,
  kVKF11 = 68,
  kVKF12 = 69,
  kVKPrintScreen = 70,
  kVKScrollLock = 71,
  kVKPause = 72,
  kVKInsert = 73,
  kVKHome = 74,
  kVKPageUp = 75,
  kVKDeleteForward = 76,
  kVKEnd = 77,
  kVKPageDown = 78,
  kVKRight = 79,
  kVKLeft = 80,
  kVKDown = 81,
  kVKUp = 82,
  kKPNumLock = 83,
  kKPDivide = 84,
  kKPMultiply = 85,
  kKPSubtract = 86,
  kKPAdd = 87,
  kKPEnter = 88,
  kKP1 = 89,
  kKP2 = 90,
  kKP3 = 91,
  kKP4 = 92,
  kKP5 = 93,
  kKP6 = 94,
  kKP7 = 95,
  kKP8 = 96,
  kKP9 = 97,
  kKP0 = 98,
  kKPPoint = 99,
  kVKNonUSBackslash = 100,
  kKPEquals = 103,
  kVKF13 = 104,
  kVKF14 = 105,
  kVKF15 = 106,
  kVKF16 = 107,
  kVKF17 = 108,
  kVKF18 = 109,
  kVKF19 = 110,
  kVKF20 = 111,
  kVKF21 = 112,
  kVKF22 = 113,
  kVKF23 = 114,
  kVKF24 = 115,
  kVKHelp = 117,
  kVKMenu = 118,
  kVKLeftControl = 224,
  kVKLeftShift = 225,
  kVKLeftAlt = 226,
  kVKLeftGUI = 227,
  kVKRightControl = 228,
  kVKRightShift = 229,
  kVKRightAlt = 230,
  kVKRightGUI = 231
};

/* Gets the next key pressed in the keyboard event cue. */
inline int CInKey();

/* Gets the pressed state of the vk_code. */
inline bool CInState(int vk_code);

struct KeyId {
  int vk_code;
  const char* label;
  const char* description;

  KeyId(VKCode code, const char* label);

  void ReprogramConsole();
};

}  // namespace _

#endif  //< #ifndef INCLUDED_KABUKI_F2_VK
#endif  //< #if SEAM >= SEAM_00_00_00__01
