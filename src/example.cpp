#include <iostream>
#include <vector>
#include "DateParser.h"
#include "RelativeDateHandler.h"
#include "Utils.h"

void displayParsedDate(const std::string &input)
{
    auto parsedDate = DateParser::parseDate(input);
    if (parsedDate)
    {
        std::cout << "Input: " << input << " --> Parsed Date: " << asctime(&*parsedDate);
    }
    else
    {
        std::cout << "Input: " << input << " --> Failed to parse the date." << std::endl;
    }
}

int main()
{

    std::vector<std::string> examples = {
        "2024-12-25",
        "25-12-2024",
        "July 4, 2024",
        "yesterday",
        "today",
        "tomorrow",
        "abcd"};

    for (const auto &example : examples)
    {
        displayParsedDate(example);
    }

    return 0;
}
