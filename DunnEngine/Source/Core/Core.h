#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

/// <summary>
/// 
/// This is a file that includes some core functionalities needed by the engine/client.
/// This for now includes assertions and in the future will include definitions for different stuff for different platforms (Windows, mac, linux, android, iphone)
/// 
/// </summary>

#include "Logger.h"

#ifdef DE_DEBUG
#define DE_ENABLE_ASSERT
#endif

// If enabled this assert macro will evaluate the arguments given to it and if there is an error it will cause the program to stop and break at the
// problomatic line and displaying the specified message given to it. If it is not enabled THE ENTIRE LINE WITH THE ARGUMENT GIVEN TO IT WILL BE DELETED
#ifdef  DE_ENABLE_ASSERT
#define DE_CORE_ASSERT(x, ...) { if(!(x)) { LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }	// engine assertion
#define DE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }			// Client assertion
#else
#define DE_CORE_ASSERT(X, ...)
#define DE_ASSERT(x, ...)
#endif