#pragma once
#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Cosmos
{
	class COSMOS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};



#define CS_CORE_ERROR(...)::Cosmos::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CS_CORE_WARN(...)::Cosmos::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CS_CORE_INFO(...)::Cosmos::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CS_CORE_TRACE(...)::Cosmos::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CS_CORE_FATAL(...)::Cosmos::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define CS_ERROR(...)::Cosmos::Log::GetClientLogger()->error(__VA_ARGS__)
#define CS_WARN(...)::Cosmos::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CS_INFO(...)::Cosmos::Log::GetClientLogger()->info(__VA_ARGS__)
#define CS_TRACE(...)::Cosmos::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CS_FATAL(...)::Cosmos::Log::GetClientLogger()->fatal(__VA_ARGS__)
}