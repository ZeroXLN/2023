#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
	public:
		enum class LogLevel {
			DEBUG,
			INFO,
			WARNING,
			ERROR
		};

		static void setLogLevel(LogLevel level);
		static void log(LogLevel level, const std::string& message);

	private:
		static LogLevel s_loglevel;
};

#endif // LOGGER_H
