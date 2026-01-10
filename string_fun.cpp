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
