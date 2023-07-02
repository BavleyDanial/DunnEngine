#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

/*
		A logging class that will be responsible for the logging of the engine and the game (the client) developed by the engine.
		This logging class allows for color coded messages in the command line according to the importance of the message.
		The backend of the logging class is managed by spdlog

		An error will be displayed as a red message, a warning will be displayed as a yellow message,
		an info will be displayed as a green message, and a trace will be displayed as a normal message
*/

namespace DunnEngine {

	class Logger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;   // Holds a pointer to the instance of the core engine logger
		static std::shared_ptr<spdlog::logger> s_ClientLogger; // Holds a pointer to the instance of the client logger
	};

}

// Definitions for the functions that will be used for logging, this makes it easier to write
// For example: We can use CORE_TRACE("something") instead of DunnEngine::Logger::GetCoreLogger()->trace("something")
#define LOG_CORE_TRACE(...)			::DunnEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)			::DunnEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)			::DunnEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)			::DunnEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)

#define LOG_TRACE(...)				::DunnEngine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)				::DunnEngine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)				::DunnEngine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)				::DunnEngine::Logger::GetClientLogger()->error(__VA_ARGS__)
