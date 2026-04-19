#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int dist_max = 0;
        int p1 = 0;
        int p2 = 0;
        while (p1<nums1.size() && p2<nums2.size()) {
            if (nums1[p1] <= nums2[p2]) {
                if (p2-p1 > dist_max) {
                    dist_max = p2-p1;
                }
                ++p2;
            } else {
                ++p1;
            }
        }
        return dist_max;
    }
};


int main() {
    Solution s;
    std::vector<int> nums1 = {55,30,5,4,2}, nums2 = {100,20,10,10,5};
    int d = s.maxDistance(nums1, nums2);
    assert(d == 2);

    nums1 = {2,2,2}, nums2 = {10,10,1};
    d = s.maxDistance(nums1, nums2);
    assert(d == 1);

    nums1 = {30,29,19,5}, nums2 = {25,25,25,25,25};
    d = s.maxDistance(nums1, nums2);
    assert(d == 2);

    return 0;
}
