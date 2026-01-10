#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>
#include <vector>

namespace window
{
    typedef std::int32_t i32;
    typedef std::int64_t i64;

    i32 find(const std::vector<i32>& nums, i32 k);
}




#endif