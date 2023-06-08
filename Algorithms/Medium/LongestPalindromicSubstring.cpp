#include <iostream>
#include <cassert>


// Given a string s, return the longest palindromic substring in s

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        size_t win_size = 1;
        size_t palindrom_len = 0;
        std::string palindrom_substring;

        if(s.size()==1) {
            return s;
        }

        for(win_size = s.size(); win_size>1 && palindrom_len == 0; --win_size)
            for(size_t i=0; i<=s.size()-win_size; ++i) {
                bool is_palindrom = true;
                size_t k = 0;
                for(size_t j=i; j<i+win_size/2; ++j) {
                    if(s[j] != s[i+win_size-1-k]) {
                        is_palindrom = false;
                        break;
                    }
                    k++;
                }
                if(is_palindrom) {
                    palindrom_len = win_size;
                    palindrom_substring = s.substr(i, win_size);
                    break;
                }
            }
        if(palindrom_substring == "") {
            palindrom_substring = s[0];
        }
        
        return palindrom_substring;
    }
};

int main() {
    Solution solution;

    assert(solution.longestPalindrome("babad") == "bab");
    assert(solution.longestPalindrome("cbbd") == "bb");

    std::cout << __FILE_NAME__ <<" Tests Ok!" << std::endl;

    return 0;
}