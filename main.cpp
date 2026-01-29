#include <iostream>
#include <vector>
#include <cstdint>
#include "window.h"
#include "string_fun.hpp"
#include <bitset>
#include <format>
#include <chrono>
#include <print>
#include <fstream>
#include <iterator>
#include <array>
#include <unordered_map>
#include <set>


using i32 = std::int32_t;
using u32 = std::uint32_t;
using i8 = std::int8_t;
using u8 = std::uint8_t;

bool isTodayBefore(i32 yy)
{
    auto today = std::chrono::system_clock::now();
    i32 year = std::stoi(std::format("{:%Y}", today));
    return year > yy;
}


void helloWorld()
{
    std::cout << "Hello World" << "\n";
    std::int8_t x = 10;
    if (x > 9)
    {
        std::cout << "Yes this is true";
    }
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void countDown(std::int32_t x)
{
    for (size_t i = x; i > 0; i--)
    {
        std::cout << std::format("Count Down: {}\n", i);
    }
}

void countUp(std::int32_t x)
{
    for (size_t i = 0; i < x; i++)
    {
        std::cout << std::format("Count Up: {}\n", i);
    }
}

void cpp_array() {
  constexpr int kArraySize = 5;
  float grades[kArraySize] = {50.23, 100.00, 92.33};
  std::string names[] = {"Alice", "Bob", "Charlie"}; // lets the compiler determine the size
  for (const auto& g : grades) {
    std::cout << g << " ";
  }
  std::cout << "\n";
  for (const auto& n : names) {
    std::cout << n << " ";
  }
  std::cout << "\n";
  std::cout << std::format("Array Size Bytes: {}, Array capacity {}", sizeof(grades), kArraySize);
  std::cout << "\n";
}

bool dynamic_array() {
  auto arr = std::vector<int> {};
  arr.push_back(10);
  arr.push_back(22);
  arr.push_back(33);
  arr.push_back(66);
  for (const auto& x : arr) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  {
    std::vector<int> arr = {1, 2};
    std::cout << "Hidden Size .." << arr.size() << "\n";
  }
  return arr.size() > 0;
}

bool isDynamicArray()
{
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    return arr.size() == 5;
}

bool is_pali(const std::string& x) {
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

bool is_same_sum(const std::vector<i32>& x, const std::vector<i32>& y);

std::vector<i32> combine_two_sorted(const std::vector<i32>& x, const std::vector<i32>& y);

void test_chrono() {
    auto text = std::format("{1} vs {0}", 42, 100); // 100 vs 42
    std::cout << text << "\n";
    auto curr = std::chrono::system_clock::now();
    auto currYear = std::format("{:%Y}", curr);
    std::cout << "The current year is: " << currYear << "\n";
    auto currDay = std::format("{:%d}", curr);
    std::cout << "The current day is: " << currDay << "\n";
    auto currMonth = std::format("{:%m}", curr);
    std::cout << "The current month is: " << currMonth << "\n";
    auto currTime = std::format("{:%H:%M:%S}", curr);
    std::cout << "The current time is: " << currTime << "\n";
}

void test_iterator_stl() {
  std::array<std::string, 10> name {"jam", "sally", "mally"};
  for (auto it = name.begin(); it != name.end(); ++it) {
    std::cout << std::format("{}\n", *it);
  }
  //
  std::vector<int> v;
}

void testChronoAgain() {
  auto datetime = std::chrono::system_clock::now();
  datetime += std::chrono::hours(24);
  std::cout << std::format("The date is {}\n", datetime);
  std::cout << std::format("The month is {:%m}\n", datetime);
  std::cout << std::format("The year is {:%Y}\n", datetime);
  std::cout << std::format("The day is {:%d}\n", datetime);
  std::cout << std::format("The Time is {:%T} UTC\n", datetime);

  struct Company {
    int id;
    std::string name;
    std::string address;
  };
  auto ex2 = Company{1, "EXAMPLE_CORP", "EXAMPLE_ADDRESS_LINE"};
  std::cout << std::format("{}", ex2.id);
}

void practiceSet()
{
    std::set<int> s;
    int x = 10;
    int y = 10;
    while (x > 0)
    {
        s.insert(x);
        x--;
    }
    while (y > 0)
    {
        s.insert(x);
        y--;
    }
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

void practiceHashMap()
{
    enum STATE
    {
        WIN = 1,
        LOSE = 0,
    };
    std::unordered_map<float, STATE> teams;
    teams[1.0f] = STATE::WIN;
    teams[2.0f] = STATE::LOSE;
    teams[3.0f] = STATE::WIN;
    teams[4.0f] = STATE::LOSE;
    teams[5.0f] = STATE::WIN;
    for (const auto& [key, value] : teams)
    {
        std::string statement = std::format("{{ {}:{} }}\n", key, static_cast<int>(value));
        std::cout << statement;
    }
    enum Teams
    {
       USF = 1,
        FSU = 2,
        UCF = 3,
    };
    std::unordered_map<Teams, int> teamScore;
    teamScore[USF] = 100;
    teamScore[FSU] = 100;
    teamScore[UCF] = 100;
    for (const std::pair<Teams, int> pair : teamScore)
    {
        std::cout << std::format("{{ {}:{} }}\n", static_cast<int>(pair.first), pair.second);
    }
}

int main()
{
    practiceSet();
    return 0;
}

bool is_same_sum(const std::vector<i32>& x, const std::vector<i32>& y) {
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

std::vector<i32> combine_two_sorted(const std::vector<i32>& x, const std::vector<i32>& y) {
    size_t leftArrayPTR = 0;
    size_t rightArrayPTR = 0;
    std::vector<i32> result;

    while (leftArrayPTR < x.size() && rightArrayPTR < y.size()) {
        if (x[leftArrayPTR] == y[rightArrayPTR]) {
            result.push_back(x[leftArrayPTR]);
            result.push_back(y[rightArrayPTR]);
            ++leftArrayPTR;
            ++rightArrayPTR;
        } else if (x[leftArrayPTR] < y[rightArrayPTR]) {
            result.push_back(x[leftArrayPTR]);
            ++leftArrayPTR;
        } else {
            result.push_back(y[rightArrayPTR]);
            ++rightArrayPTR;
        }
    }
    while (leftArrayPTR < x.size()) {
        result.push_back(x[leftArrayPTR]);
        leftArrayPTR++;
    }
    while (rightArrayPTR < y.size()) {
        result.push_back(y[rightArrayPTR]);
        rightArrayPTR++;
    }
    return result;
}
