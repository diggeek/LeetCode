#include <cassert>
#include <iostream>
#include <vector>


// You are given an array of characters letters that is sorted in non-decreasing order, 
// and a character target. 
// There are at least two different characters in letters.
// Return the smallest character in letters that is lexicographically greater than target. 
// If such a character does not exist, return the first character in letters.

// Example 1:
// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

// Example 2:
// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

// Example 3:
// Input: letters = ["x","x","y","y"], target = "z"
// Output: "x"
// Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].


class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        int l = -1;
        int r = letters.size()-1;
        int mid = (l + r) / 2;
        while (r-l > 1) {
            mid = (l + r) / 2;
            printf("mid = %d\n", mid);
            if (letters[mid] < target) {
                l = mid;
                printf("l = %d\n", l);
            } else {
                r = mid;
                printf("r = %d\n", r);
            }
        }

        while (letters[r] <= target) {
            if(++r == static_cast<int>(letters.size())) {
                return letters[0];
            }
        }

        return letters[r];
    }
};


int main() {
    Solution solution;

    std::vector<char> letters {'c', 'f', 'j'};
    char target = 'a';
    assert(solution.nextGreatestLetter(letters, target) == 'c');
    
    letters = {'c', 'f', 'j'};
    target = 'c';
    assert(solution.nextGreatestLetter(letters, target) == 'f');

    letters = {'x', 'x', 'y', 'y'};
    target = 'z';
    assert(solution.nextGreatestLetter(letters, target) == 'x');

    std::cout << __FILE_NAME__ <<" Tests Ok!" << std::endl;

    return 0;
}
