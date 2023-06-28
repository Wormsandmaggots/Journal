//
// Created by 48782 on 04.06.2023.
//

#ifndef OPENGL_LOGGER_H
#define OPENGL_LOGGER_H

#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

class Logger {

public:
    static void log(const std::string& message, const char* color, spdlog::level::level_enum level);
    static void log(const std::string& message, const char* color, const char* level);

    ~Logger() = default;

private:
    static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink;
    static spdlog::logger logger;
};


#endif //OPENGL_LOGGER_H
