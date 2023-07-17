#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to DunnGames to use this software for any purpose,
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


// Some core functionalities

#include "Logger.h"

#ifdef DE_DEBUG
#define DE_ENABLE_ASSERT
#endif

// If enabled this assert macro will evaluate the arguments given to it and if there is an error it will cause the program to stop and break at the
// problomatic line and displaying the specified message given to it. If it is not enabled THE ENTIRE LINE WITH THE ARGUMENT GIVEN TO IT WILL BE DELETED
#ifdef  DE_ENABLE_ASSERT
#define DE_CORE_ASSERT(x, ...) { if(!(x)) { LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }	// engine assertion
#define ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }			// Client assertion
#else
#define DE_CORE_ASSERT(X, ...)
#define DE_ASSERT(x, ...)
#endif