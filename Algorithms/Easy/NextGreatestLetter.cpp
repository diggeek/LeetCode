#include <iostream>
#include <vector>
#include <cassert>

// You are given an array of characters letters that is sorted in non-decreasing order, 
// and a character target. 
// There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. 
// If such a character does not exist, return the first character in letters.


class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        int mid = letters.size() / 2;
        int begin = 0, end = letters.size()-1;
        while (begin < end) {
            if (letters[mid] > target) {
                end = mid - 1;
            } else if (letters[mid] < target) {
                begin = mid + 1;
            } else {
                break;
            }
            mid = begin + (end-begin)/2;
        }

        while (letters[mid] <= target) {
            if(++mid == static_cast<int>(letters.size())) {
                return letters[0];
            }
        }

        return letters[mid];
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