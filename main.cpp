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


using i32 = std::int32_t;
using u32 = std::uint32_t;

void hello_world() {
    std::cout << "Hello World" << "\n";
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

void test_google_format() {
  std::string name = "Google";
  std::cout << std::format("Hello {} format\n", name);
  std::int8_t i = 0;
  std::cout << std::format("Number {}\n", i);
}


int main() {
  hello_world();
  // 3443
  const std::string inputValue = "3443";
  const bool result = is_pali(inputValue);
  std::cout << std::boolalpha;
  std::cout << result << "\n";
  std::cout << "===================" << "\n";
  const std::vector<i32> x = {20, 30, 40};
  const std::vector<i32> y = {40, 30, 20};
  std::cout << is_same_sum(x, y) << "\n";
  std::cout << "===================" << "\n";
  std::cout << "===================" << "\n";
  const auto a1 = std::vector<i32> {10, 20, 30, 40};
  const auto a2 = std::vector<i32> {5, 10, 15, 20, 50};
  const auto foo = combine_two_sorted(a1, a2);
  for (const auto& r : foo) {
      std::cout << r << " ";
  }
  std::cout << "\n";
  std::cout << "===================" << "\n";
  std::cout << "===================" << "\n";

  std::vector<i32> windowFindInput = {10, 5, 7, 10, 10};
  constexpr i32 target = 20;
  i32 windowResult = window::find(windowFindInput, target);
  std::cout << "Window Result: " << windowResult << "\n";
  std::cout << "================" << std::endl;
  testConvertToNumber("22");
  std::cout << "================" << std::endl;
  auto r = testConvertToNumberBase2("10110");
  std::cout << r << std::endl;
  std::cout << "================" << std::endl;
  testConvertDouble("23.23");
  testConvertFloat("400.23");
  // pracChar32();
  std::cout << "Hello" << std::endl;
  std::cout << "Hello" << std::endl;
  auto text = std::format("{} is {}", 10, 10);
  std::cout << text << "\n";
  test_chrono();
  std::print("The answer is {}\n", 42);
  std::println("I am printing a line {}", 200);
  std::println("==================");
  std::FILE* F = std::fopen("cool.txt", "w");
  if (F) {
      std::println(F, "Writing to the file");
      std::println(F, "Writing to the file");
      std::println(F, "Writing to the file");
      std::fclose(F);
  }
  std::fstream RF("cool.txt");
  if (!RF.is_open()) {
      std::cerr << "Error opening file\n";
  }
  std::string line;
  while (std::getline(RF, line)) {
      std::cout << std::format("Line: {}\n", line);
  }
  std::println("==================");
  test_google_format();
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
