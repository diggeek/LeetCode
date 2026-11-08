#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.

// Example 1:
// Input: nums = [3,0,1]
// Output: 2
// Explanation:
// n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
// 2 is the missing number in the range since it does not appear in nums.

// Example 2:
// Input: nums = [0,1]
// Output: 2
// Explanation:
// n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 
// 2 is the missing number in the range since it does not appear in nums.

// Example 3:
// Input: nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// Explanation:
// n = 9 since there are 9 numbers, so all numbers are in the range [0,9].
// 8 is the missing number in the range since it does not appear in nums


int missingNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    
    if(nums.back() == nums.size()-1) {
        return nums.size();
    }

    int l = 0;
    int r = nums.size() - 1;
    int mid = (l+r) / 2;
    while (l < r) {
        printf("mid = %d\n", mid);
        if (nums[mid] == mid) {
            l = mid + 1;
            printf("l = %d\n", l);
        } else {
            r = mid - 1;
            printf("r = %d\n", r);
        }
        mid = (l+r) / 2;
    }
    return nums[mid] == mid ? mid+1 : mid;
}


int main(void) {
    std::vector<int> nums = {3,0,1};
    int mis = missingNumber(nums);
    printf("mis = %d\n", mis);
    assert(mis == 2);
    std::cout << "======" << std::endl;

    nums = {0,1};
    mis = missingNumber(nums);
    printf("mis = %d\n", mis);
    assert(mis == 2);
    std::cout << "======" << std::endl;

    nums = {9,6,4,2,3,5,7,0,1};
    mis = missingNumber(nums);
    printf("mis = %d\n", mis);
    assert(mis == 8);
    std::cout << "======" << std::endl;

    nums = {1,2};
    mis = missingNumber(nums);
    printf("mis = %d\n", mis);
    assert(mis == 0);
    std::cout << "======" << std::endl;

    nums = {0,2,3};
    mis = missingNumber(nums);
    printf("mis = %d\n", mis);
    assert(mis == 1);
    std::cout << "======" << std::endl;
}
