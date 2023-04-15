#include <iostream>
#include <vector>
#include <map>
#include <cassert>

// https://leetcode.com/problems/two-sum/description/
// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, std::vector<int>> nums_tree;
        // O(n)
        for (size_t i=0; i<nums.size(); ++i) {
            nums_tree[nums[i]].push_back(i);
        }

        for (auto& [key, value] : nums_tree) {
            int new_target = target - key;
            if (nums_tree.count(new_target)) {
                if (new_target == key) {
                    return std::vector<int> {value[0], value[1]};
                }
                return std::vector<int> {value[0], nums_tree.at(new_target)[0]};
            }
        }
        return std::vector<int>(2, 0);
    }
};

int main() {
    Solution solution;

    std::vector<int> nums {2,7,11,15};
    int target = 9;
    std::vector<int> expect {0, 1};
    assert(expect == solution.twoSum(nums, target));

    nums = {3,2,4};
    target = 6;
    expect = {1, 2};
    assert(expect == solution.twoSum(nums, target));

    nums = {3, 3};
    target = 6;
    expect = {0, 1};
    assert(expect == solution.twoSum(nums, target));

    std::cout << __FILE_NAME__ <<" Ok!" << std::endl;

    return 0;
}
