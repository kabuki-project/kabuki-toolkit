/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/t_controller.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_AV_1
#ifndef kabuki.toolkit_AV_CONTROL
#define kabuki.toolkit_AV_CONTROL

#include "t_component.h"

namespace _ {

/* A group of touch::Parameter(s).
 */
class LIB_MEMBER Controller {
 public:
  enum {
    MaxTemplates =
        1024,         //< The max amount of templates (Should there be one?).
    MaxTempo = 999,   //< The max allowed tempo
    MinTicksPerBeat,  //< The min number of ticks per MIDI beat.
    MaxTicksPerBeat,  //< The max number of ticks per MIDI beat.
    MinNumModes = 2,  //< The min number of modes on a ISymmetric HUI.
    MinTicksPerBeat =
        24,  //< The min number of MIDI quarter note subdivisions supported.
    MaxTicksPerBeat =
        960,  //< The max number of MIDI quarter note subdivisions supported.

    MinTempo = 1,                   //< The min tempo allowed.
    MaxTempo = 960,                 //< The max tempo allowed.
    DefaultEncoderAcceleration = 1  //< The default encoder acceleration.
  };

  /* Contrustor. */
  Controller(SI4 initCommonChannel = 0, SI4 initKeyboardChannel = 1,
             SI4 initDrumsChannel = 7);

  /* Copy constructor. */
  Controller(const Controller& o);

  /* Destructor. */
  ~Controller();

  /* Processes a MIDI beat sub-division. */
  void UpdateMIDIClock();

  /* Processes a MIDI quarter note beat. */
  void ProcessMIDIQuaterNote();

  /* Gets the number of ticks per MIDI quarter note beat. */
  SI4 GetTicksPerBeat();

  /* Sets the ticksPerBeat to the newNumTicks. */
  void SetTicksPerBeat(SI4 newNumTicksPerBeat);

  /* Gets the current tempo. */
  SI4 Tempo();

  /* Sets the tempo to the newTempo. */
  void SetTempo(FP8 newTempo);

  /* Starts the MIDI engine. */
  void Start();

  /* Stops  the MIDI engine. */
  void Stop();

  /* Processes a fast-forward button press. */
  void Forward();

  /* Processes a rewind button press. */
  void Backward();

  /* Gets the FP8 press time in seconds. */
  FP8 GetDoublePressTime();

  /* sets the double_press_ticks to the newTime in seconds.
      @return gets -1 if the newTime is to small, 1 if it is to
          big, and 0 upon success */
  SI4 SetDoublePressTime(FP8 newTime);

  /* Prints this object to a AString. */
  template<typename Printer> Printer& Print(Printer& o) const;

 private:
  SI4 common_channel_,     //< Common MIDI Channel  (0)
      channel_keyboard_,   //< Keyboard MIDI out channel
      drums_channel_,      //< Drums MIDI out channel
      double_press_ticks_;  //< "Double press", or "FP8 click" time.

};
}  // namespace _
#endif
#endif