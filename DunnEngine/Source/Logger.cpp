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


#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace DunnEngine {

	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger = nullptr;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger = nullptr;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");					 // Set the pattern of the message to be [Time] [logger kind]: message
		s_CoreLogger = spdlog::stdout_color_mt("DunnEngine");	 // Set the color of the messaging
		s_CoreLogger->set_level(spdlog::level::trace);			 // Set the default message importance

		s_ClientLogger = spdlog::stdout_color_mt("DunnSandbox"); // Set the color of the messaging
		s_ClientLogger->set_level(spdlog::level::trace);		 // Set the default message importance
	}															 

}