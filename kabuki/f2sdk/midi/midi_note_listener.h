/** Kabuki Toolkit
    @file    ~/library/kabuki/toolkit/midi/midi_note_listener.h
    @author  Cale McCollough <calemccollough.github.io>
    @license Copyright (C) 2014-2017 Cale McCollough <calemccollough@gmail.com>;
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
#include <pch.h>

#pragma once

namespace _ {

class IMIDIKeyboard
{
    public:

    virtual void midiNoteOn (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) = 0;

    virtual void midiNoteOff (MidiKeyboardState*, int midiChannel, int midiNoteNumber, /*float velocity*/) = 0;
};

}       //< namespace _
