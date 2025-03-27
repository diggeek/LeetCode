#include "problems.hpp"

int lengthOfLongestSubstring(std::string s) {
    int len_max = 0;
    int len = 0;
    for (size_t i=0; i<s.size();++i) {
        int table[128] = {};
        for (size_t j=i; j<s.size(); ++j) {
            if (table[(int)s[j]] == 0) {
                table[(int)s[j]] = j + 1;
                ++len;
            } else {
                i = table[(int)s[j]]-1;
                break;
            }
        }
        if (len_max < len) {
            len_max = len;
        }
        len = 0;
    }

    return len_max;
}
