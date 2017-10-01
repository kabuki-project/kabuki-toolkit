/** The Chinese Room
    @version 0.x
    @file    ~/chinses_room/impl/terminal.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough<calemccollough.github.io>
                            All right reserved (R).
             Licensed under the Apache License, Version 2.0 (the "License"); 
             you may not use this file except in compliance with the License. 
             You may obtain a copy of the License at
                        http://www.apache.org/licenses/LICENSE-2.0
             Unless required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#include "../include/terminal.h"
#include "../include/verifier.h"

namespace _ {

Terminal::Terminal (Verifier* io) :
    io_ (io)
{
}

Terminal::~Terminal () {
    //if (io_->type > 0) Delete<Uniprinter> (io_);
}

bool Terminal::Contains (void* address) {
    return VerifierContains (io_, address);
}

const Member* Terminal::Op (byte index, Verifier* io) override {
    switch (index) {
        case 0:
            break;
    }
    return 0;
}

}       //< namespace _