#pragma once

// Auther: Bavley Danial
// Date: 7/11/2023
//
// TDE - The Dunn Engine
//

/// <summary>
/// 
/// This file includes the Logger class. This class is responsible for all the logging from both engine and client sides.
/// This class can log an error, a trace, an info, a warnning, into the console and in the future in files.
/// This class can not be instantiated as an object as there is only one instance of it.
/// 
/// </summary>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace DunnEngine {

	class Logger
	{
	public:
		//--------------------------------- ENGINE SIDE FUNCTIONS ---------------------------------\\

		// Initialises the logging class with the correct printing format and color coding
		static void Init();
		// Returns a pointer to the core logger. This is reserved for potential debugging needs.
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		// Returns a pointer to the client logger. This is reserved for potential debugging needs.
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;   // Holds a pointer to the instance of the core engine logger
		static std::shared_ptr<spdlog::logger> s_ClientLogger; // Holds a pointer to the instance of the client logger
	};

}

// Definitions for the functions that will be used for logging, this makes writing a log easier.
// For example: We can use CORE_TRACE("something") instead of DunnEngine::Logger::GetCoreLogger()->trace("something")
#define LOG_CORE_TRACE(...)			::DunnEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)			::DunnEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)			::DunnEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)			::DunnEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)

#define LOG_TRACE(...)				::DunnEngine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)				::DunnEngine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)				::DunnEngine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)				::DunnEngine::Logger::GetClientLogger()->error(__VA_ARGS__)
