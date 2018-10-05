/** Kabuki Toolkit
    @file    $kabuki-toolkit/kabuki/toolkit/app/event_sequence.h
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
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

namespace _ {

class EventSequence;

class EventNode
/*< An IEvent node in a linear linked list. */
{
    _Noncopyable_(EventNode)
	
    public:
    
    EventNode(IEvent* nodeEvent);
    /*< Constructs an event node with the given IEvent. */

    EventNode* getNext();
    /*< Gets the next IEvent */
    
    IEvent* getEvent();
    /*< Gets the event this node triggers. */

    void setEvent(IEvent* newEvent);
    /*< Sets the event this node triggers. */

    void trigger(EventSequence* source);
    /*< Triggers the event. */

    void print () const;
    /*< Prints this object to the stdout. */
    
    private:
    
    IEvent* iEvent;             //< The event this node triggers.
    EventNode* next;            //< The next node in the LLL.
};

class EventSequence : public _::IEvent
/** A sequence of events stored as a linear linked list. */
{
    _Noncopyable_(EventSequence)
	
    public:
    
    EventSequence();
    /*< Constructs an empty event sequence. */

    void trigger();
    /*< Triggers the event. */

    void print () const;
    /*< Prints this object to the stdout. */

    private:
	
    EventNode* head;            //< Head of the linear linked list of IEventNode(s).
    timestamp_t eventTime;      //< The time in microseconds the event occurred.
};

}       //< namespace _
#endif  //< HEADER_FOR_KABUKI_TOOLKIT_APP_EVENTSEQUENCE
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
