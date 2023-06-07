#include <iostream>
#include <cassert>

// Given 3 positives numbers a, b and c. 
// Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
// Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = (a | b) ^ c;
        if (d == 0) {
            return 0;
        }

        int cnt_bit = 0;
        while (d) {
            if (d&1) {
                if (c&1) {
                    ++cnt_bit;
                } else {
                    if ((a ^ b) & 1) {
                        ++cnt_bit;
                    } else {
                        cnt_bit += 2;
                    }
                }
            }
            d >>= 1;
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return cnt_bit;
    }
};

int main() {
    Solution solution;

    assert(solution.minFlips(2, 6, 5) == 3);
    assert(solution.minFlips(4, 2, 7) == 1);
    assert(solution.minFlips(1, 2, 3) == 0);
    assert(solution.minFlips(255, 255, 0) == 16);
    assert(solution.minFlips(0, 0, 511) == 9);

    std::cout << __FILE_NAME__ <<" Tests Ok!" << std::endl;
    
    return 0;
}
