#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel {
	class HAZEL_API Log
	{

	public:
		static void Init();
		//引擎日志
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}
		//客户端日志
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


//Core log macros
#define HZ_CORE_ERROR(.../*这里为宏变量*/) ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)//将宏中的变量参数转发给实际函数
#define HZ_CORE_WARN(...) ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...) ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_CLIENT_ERROR(.../*这里为宏变量*/) ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)//将宏中的变量参数转发给实际函数
#define HZ_CLIENT_WARN(...) ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_CLIENT_INFO(...) ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_CLIENT_TRACE(...) ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_CLIENT_FATAL(...) ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
