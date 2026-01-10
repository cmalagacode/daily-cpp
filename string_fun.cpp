#include "string_fun.hpp"
#include <iostream>
#include <cstdint>

void testConvertToNumber(std::string x)
{
    std::int32_t resultA = std::stoi(x);
    std::cout << resultA << std::endl;
}

std::bitset<8> testConvertToNumberBase2(std::string x)
{
    auto result = std::stoi(x, nullptr, 2);
    return result;
}

void testConvertFloat(std::string x)
{
    auto result = std::stof(x);
    std::cout << result << std::endl;
}
void testConvertDouble(std::string x)
{
    auto result = std::stod(x);
    std::cout << result << std::endl;
}
void pracChar32()
{
    char32_t emoji = '😁';
    std::string s(1, emoji);
    std::cout << "This is an emoji smily face: " << s  << std::endl;
}
