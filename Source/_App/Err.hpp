////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2016 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_ERR_HPP
#define SFML_ERR_HPP

#include <ChineseRoom-Config.hpp>
#include <ostream>


namespace _ {
    
_ChineseRoom_ std::ostream& err ();
/*< Standard stream used by SFML to output warnings and errors
    @ingroup system
   
    By default, _::err () outputs to the same location as std::cerr,
 (-> the stderr descriptor) which is the console if there's
    one available.
   
    It is a standard std::ostream instance, so it supports all the
    insertion operations defined by the STL
 (operator <<, manipulators, etc.).
   
    _::err () can be redirected to write to another output, independently
    of std::cerr, by using the rdbuf () function provided by the
    std::ostream class.
   
    Example:
    @code
    // Redirect to a file
    std::ofstream file ("sfml-log.txt");
    std::streambuf* previous = _::err ().rdbuf (file.rdbuf ());
   
    // Redirect to nothing
    _::err ().rdbuf (nullptr);
   
    // Restore the original output
    _::err ().rdbuf (previous);
    @endcode
   
    @return Reference to std::ostream representing the SFML error stream. */

} //< _


#endif // SFML_ERR_HPP
