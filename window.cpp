#include "window.h"

namespace window
{
    // find the largest window length for vector with k as bound to identify valid subarray
    i32 find(const std::vector<i32>& nums, const i32 k)
    {
        i32 left = 0;
        i32 right = 0;
        i32 curr = 0;
        i32 ans = 0;

        while (right < nums.size()) {
            curr += nums[right];
            while (curr > k) {
                curr -= nums[left];
                left++;
            }
            if (ans < right - left + 1) {
                ans = curr;
            }
            right++;
        }
        return ans;
    }
}
