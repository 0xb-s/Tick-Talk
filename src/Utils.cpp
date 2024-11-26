#include "Utils.h"
#include <algorithm>
#include <cctype>

std::string Utils::cleanInput(const std::string &input)
{
    std::string cleaned = input;
    cleaned.erase(remove_if(cleaned.begin(), cleaned.end(), ::isspace), cleaned.end());
    return cleaned;
}
