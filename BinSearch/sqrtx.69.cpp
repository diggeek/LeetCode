#include <cassert>
#include <cstdint>
#include <iostream>

// Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
// The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.
// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

// Example 1:
// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

// Constraints:
// 0 <= x <= 2^31 - 1


int mySqrt(int x) {
    int64_t x_ext = x;
    int64_t l = -1;
    int64_t r = (1ull<<31);
    int64_t mid = (l + r) / 2ull;
    while (r - l > 1) {
        mid = (l + r) / 2ull;
        printf("mid = %lu\n", mid);
        if (mid*mid < x_ext) {
            l = mid;
            printf("l = %lu\n", l);
        } else {
            r = mid;
            printf("r = %lu\n", r);
        }
    }

    int sqrt = r*r == x ? r : r-1;
    printf("x = %d, sqrt = %d\n", x, sqrt);
    printf("=====\n");
    return sqrt;
}

int main(void) {
    int sqrt = mySqrt(4);
    assert(sqrt == 2);

    sqrt = mySqrt(8);
    assert(sqrt == 2);

    sqrt = mySqrt(2);
    assert(sqrt == 1);

    sqrt = mySqrt(3);
    assert(sqrt == 1);

    return 0;
}
