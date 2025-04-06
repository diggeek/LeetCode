#include <iostream>
#include <cassert>

#include "problems.hpp"


int main() {
    assert(longestPalindrome("babad") == "bab");
    assert(longestPalindrome("cbbd") == "bb");

    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring("aab") == 2);

    {
        std::vector<std::vector<int>> times = {{3,10},{1,5},{2,6}};
        assert(smallestChair(times, 0) == 2);
        times = {{99999,100000},{1,2}};
        assert(smallestChair(times, 0) == 0);
    }

    {
        std::vector<std::vector<int>> matrix {{1,1,1},{1,0,1},{1,1,1}};
        std::vector<std::vector<int>> expected_matrix {{1,0,1},{0,0,0},{1,0,1}};
        setZeroes(matrix);
        assert(matrix == expected_matrix);

        matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        expected_matrix = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
        setZeroes(matrix);
        assert(matrix == expected_matrix);
    }

    std::cout << " Tests Ok!" << std::endl;

    return 0;
}
