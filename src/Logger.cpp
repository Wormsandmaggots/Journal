//
// Created by 48782 on 04.06.2023.
//

#include <map>
#include <string>
#include "Logger.h"

std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> Logger::console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
spdlog::logger Logger::logger = spdlog::logger("", console_sink);


std::map<std::string, std::string> colors = {
        {"black",   "\033[0;30m"},
        {"red",     "\033[0;31m"},
        {"green",   "\033[0;32m"},
        {"yellow",  "\033[0;33m"},
        {"blue",    "\033[0;34m"},
        {"magenta", "\033[0;35m"},
        {"cyan",    "\033[0;36m"},
        {"white",   "\033[0;37m"},
        {"reset",   "\033[0m"}
};

std::map<std::string, spdlog::level::level_enum> levels = {
        {"trace",   spdlog::level::trace},
        {"debug",   spdlog::level::debug},
        {"info",    spdlog::level::info},
        {"warn",    spdlog::level::warn},
        {"error",   spdlog::level::err},
        {"critical",spdlog::level::critical},
        {"off",     spdlog::level::off}
};

void Logger::log(const std::string& message, const char* color, spdlog::level::level_enum level) {

    if (colors[color].empty())
    {
        logger.warn("Invalid color: {}", color);
    }

    const std::string formattedMsg = colors[color] + message + colors["reset"];
    logger.log(level, formattedMsg);
}

void Logger::log(const std::string& message, const char *color, const char *level) {

    if (colors[color].empty())
    {
        logger.warn("Invalid color: {}", color);
    }

    const std::string formattedMsg = colors[color] + message + colors["reset"];
    logger.log(levels[level], formattedMsg);
}