#ifndef DATEPARSER_H
#define DATEPARSER_H

#include <string>
#include <optional>
#include <ctime>

class DateParser
{
public:
    // Static method to parse a date string into a tm structure
    static std::optional<std::tm> parseDate(const std::string &input);
};

#endif
