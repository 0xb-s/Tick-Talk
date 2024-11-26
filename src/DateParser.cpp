#include "DateParser.h"
#include "Utils.h"
#include "RelativeDateHandler.h"
#include <sstream>
#include <iomanip>

std::optional<std::tm> DateParser::parseDate(const std::string &input)
{
    if (RelativeDateHandler::isRelativeDate(input))
    {
        return RelativeDateHandler::parseRelativeDate(input);
    }

    std::string cleanedInput = Utils::cleanInput(input);
    std::tm date = {};
    std::istringstream stream(cleanedInput);

    stream >> std::get_time(&date, "%Y-%m-%d");
    if (!stream.fail())
    {
        return date;
    }

    return std::nullopt;
}
