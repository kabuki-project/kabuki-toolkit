/** The Chinese Room
    @version 0.x
    @file    ~/chinses_room/include/symbol_table.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 [Cale McCollough] (calemccollough.github.io)
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

#ifndef CHINESE_ROOM_SYMBOLTABLE_H
#define CHINESE_ROOM_SYMBOLTABLE_H

#include "utils.h"
#include "error.h"

namespace _ {

/** A dictionary designed to work with Device (s) with less than 192 members.
    
    # Memory Layout

    @code
       _____________________________________________________
       |_______ | Key 1                                    |
       |_______ | ...                          Keys        |
       |_______ v Key N                                    |
       |___________________________________________________|
       |                                                   |
       |               Header Buffer Space                 |
       |___________________________________________________|
       |_______                                            |
       |_______   Collision List N          Hash Table     |
       |_______ ^ ...                        Collision     |
       |_______ | Collision List 0              List       |
       |___________________________________________________|
       |_______                          Element Size = 1  |
       |_______   Buffer Indexes                           |
       |_______                             Hash Table     |
       |_______ ^ Collision Table N          Unsorted      |
       |_______ | ...                         Indexes      |
       |        | Collision table 0                        |
       |___________________________________________________|
       |_______                          Element Size = 1  |
       |_______   Buffer Indexes                           |
       |_______                             Hash Table     |
       |_______ ^ Collision Index N          Collision     |
       |_______ | ...                         Indexes      |
       |        | Collision Index 0                        |
       |___________________________________________________|
       |_______                         Element Size = 2   |
       |_______   Buffer Indexes                           |
       |_______                              16-bit        |
       |_______ ^ Key Offset N                 key         |
       |_______ | ...                        Offsets       |
       |        | Key Offset 1                             |
       |___________________________________________________|
       |_______                         Element Size = 2   |
       |_______   Buffer Indexes                           |
       |_______                              16-bit        |
       |_______ ^ Sorted Hash N              Hashes        |
       |_______ | ...                                      |
       |        | Sorted Hash 1                            |
       |___________________________________________________|
     ^ |                                                   |
     | |                 Header (8 bytes)                  |
    0x0|___________________________________________________|
    @endcode
*/
/** Temp delete me 
    _____________________________________________________ 
    |_______                                            | 
    |_______   Data N                                   | 
    |_______ ^ ...                       Data Table     | 
    |_______ | Data 0                                   | 
    |___________________________________________________|
    |_______ | Key 1                                    |
    |_______ | ...                          Keys        |
    |_______ v Key N                                    |
    |___________________________________________________|
    |                                                   |
    |               Header Buffer Space                 |
    |___________________________________________________|
    |_______                                            |
    |_______   Collision List N          Hash Table     |
    |_______ ^ ...                        Collision     |
    |_______ | Collision List 0              List       |
    |___________________________________________________|
    |_______                                            |
    |_______   Buffer Indexes                           |
    |_______                             Hash Table     |
    |_______ ^ Collision Index N          Collision     |
    |_______ | ...                         Indexes      |
    |        | Collision Index 0                        |
    |___________________________________________________|
    |_______                                            |
    |_______   Buffer Indexes                           |
    |_______                             Hash Table     |
    |_______ ^ Collision Table N        Corresponding   |
    |_______ | ...                          Hash        |
    |        | Collision table 0           Indexes      |
    |___________________________________________________|
    |_______                                            |
    |_______   Buffer Indexes                           |
    |_______                                            |
    |_______ ^ Sorted Hash N                Hashes      |
    |_______ | ...                                      |
    |        | Sorted Hash 1                            |
    |___________________________________________________|
    |_______                                            |
    |_______   Buffer Indexes                           |
    |_______                                Data        |
    |_______ ^ Data Offset N              Offsets       |
    |_______ | ...                                      |
    |        | Data Offset 1                            |
    |___________________________________________________|
    |_______                                            |
    |_______   Buffer Indexes                           |
    |_______                                Key         |
    |_______ ^ Key Offset N               Offsets       |
    |_______ | ...                                      |
    |        | Key Offset 1                             |
    |___________________________________________________|
    |_______                                            |
    |_______   Buffer Indexes                           |
    |_______                               State        |
    |_______ ^ State byte N                Byte         |
    |_______ | ...                                      |
    |        | State byte 1                             |
    |___________________________________________________|
    |                                                   | ^
    |                    Header                         | |
    |___________________________________________________|0x0 
template<typename TIndex, typename TKey, typename TData, typename THash>
struct Book {
    TData size;             //< The total size of the Book.
    TKey table_size,        //< The size of the key strings in bytes.
        pile_size;          //< The size of the (optional) collisions table pile.
    TIndex num_items,       //< Number of items.
        max_items;          //< The max number of buffered items.
};*/

struct SymbolTable {
    byte num_keys,              //< Number of keys.
        max_keys;               //< Number of buffered indexes.
    uint16_t pile_size,         //< Size of the collision table pile.
        size;                   //< Size of this object in bytes.
};

enum {
    kMinSymbolTableSize = 64,   //< The min size of a SymbolTable
    kInvalidRecord      = 255,
    kMaxI2PMembers      = 192,
    kNoCollidingRecords = 255, 
    kRecordOverflow     = 254,
    kSymbolTableFull    = 253,
    kOverheadPerRecord  = sizeof (hash16_t) + sizeof (uint16_t) + sizeof (byte) + 
        sizeof (byte),
};

//inline void Print (SymbolTable* rt);

/** Constructs a streamable hash table with enough buffer space for the 
    max_keys.
    @post Users might want to call the isValid () function after 
        construction to verify the integrity of the object.
    @warning The reservedNumMembers must be aligned to a 32-bit value, and 
        it will get rounded up to the next higher multiple of 4.
*/
static SymbolTable* SymbolTableInit (byte* buffer, byte max_keys, uint16_t total_size);
    
/** Adds the given key and returns the index 64-255 of the index of the 
    member.
    @return Returns an index 64-255
*/
static byte Add (SymbolTable* rt, const char* key);

/** Attempts to find the given key.
    @return Returns 0 upon failure, and valid index upon success. */
static byte Find (const SymbolTable* rt, const char* key);

/** Prints this object out to the console. */
inline void Print (SymbolTable* rt);

}       //< namespace _
#endif  //< CHINESE_ROOM_SYMBOLTABLE_H