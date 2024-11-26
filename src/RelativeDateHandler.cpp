#include "RelativeDateHandler.h"
#include <map>
#include <ctime>

bool RelativeDateHandler::isRelativeDate(const std::string &input)
{

  // todo: add more later
    static const std::map<std::string, int> relativeKeywords = {
        {"yesterday", -1},
        {"tomorrow", 1},
        {"today", 0}};

    return relativeKeywords.find(input) != relativeKeywords.end();
}

std::optional<std::tm> RelativeDateHandler::parseRelativeDate(const std::string &input)
{
    std::tm now = {};
    time_t t = time(nullptr);
    localtime_r(&t, &now);

    static const std::map<std::string, int> relativeKeywords = {
        {"yesterday", -1},
        {"tomorrow", 1},
        {"today", 0}};

    auto it = relativeKeywords.find(input);
    if (it != relativeKeywords.end())
    {
        now.tm_mday += it->second;
        mktime(&now);
        return now;
    }

    return std::nullopt;
}
