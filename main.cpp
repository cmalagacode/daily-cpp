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

bool isSameSum(const std::vector<i32>& x, const std::vector<i32>& y);


int main()
{
    helloWorld();
    // 3443
    const std::string inputValue = "3443";
    const bool result = isPali(inputValue);
    std::cout << std::boolalpha;
    std::cout << result << "\n";
    std::cout << "===================" << "\n";
    const std::vector<i32> x = {20, 30, 40};
    const std::vector<i32> y = {40, 30, 20};
    std::cout << isSameSum(x, y) << "\n";
    std::cout << "===================" << "\n";
    return 0;
}

bool isSameSum(const std::vector<i32>& x, const std::vector<i32>& y)
{
    size_t leftArray = 0;
    size_t rightArray = 0;

    i32 leftArraySum = 0;
    i32 rightArraySum = 0;

    while (leftArray < x.size() && rightArray < y.size()) {
        leftArraySum += x[leftArray];
        rightArraySum += y[rightArray];
        leftArray++;
        rightArray++;
    }
    while (leftArray < x.size()) {
        leftArraySum += x[leftArray];
        leftArray++;
    }
    while (rightArray < y.size()) {
        rightArraySum += y[rightArray];
        rightArray++;
    }
    return leftArraySum == rightArraySum;
}
