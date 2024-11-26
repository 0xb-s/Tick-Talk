#ifndef RELATIVEDATEHANDLER_H
#define RELATIVEDATEHANDLER_H

#include <string>
#include <optional>
#include <ctime>

class RelativeDateHandler
{
public:
    static bool isRelativeDate(const std::string &input);
    static std::optional<std::tm> parseRelativeDate(const std::string &input);
};

#endif
