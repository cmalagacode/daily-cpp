#include <iostream>
#include <vector>
#include <cstdint>

using i32 = std::int32_t;
using u32 = std::uint32_t;

void helloWorld()
{
    std::cout << "Hello World" << "\n";
}

bool isPali(const std::string& x)
{
    size_t left = 0;
    size_t right = x.size() - 1;
    while (left < right) {
        if (x[left] != x[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    helloWorld();
    // 3443
    const std::string inputValue = "3443";
    const bool result = isPali(inputValue);
    std::cout << std::boolalpha;
    std::cout << result << "\n";
    return 0;
}