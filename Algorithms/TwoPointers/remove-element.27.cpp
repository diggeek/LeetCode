#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int p1=0, p2 = nums.size()-1;
        int k = 0;
        while (p1 <= p2) {
            while (nums[p2] == val) {
                --p2;
                if (p2 < 0) {
                    return k;
                }
            }
            if (nums[p1] == val) {
                std::swap(nums[p1], nums[p2]);
            } else {
                ++k;
                ++p1;
            }
        }
        return k;
    }
};


int main() {
    Solution s;
    std::vector<int> nums = {3,2,2,3};
    int d = s.removeElement(nums, 3);
    assert(d == 2);

    nums = {1};
    d = s.removeElement(nums, 1);
    assert(d == 0);

    nums = {4,5};
    d = s.removeElement(nums, 4);
    assert(d == 1);

    nums = {3,3};
    d = s.removeElement(nums, 5);
    assert(d == 2);

    return 0;
}
