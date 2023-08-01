// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
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