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

    std::cout << " Tests Ok!" << std::endl;

    return 0;
}
