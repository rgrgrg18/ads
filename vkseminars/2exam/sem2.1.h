#ifndef _sem_2_h_
#define _sem_2_h_
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using vectorIt = std::vector<int>::iterator;

class Solution {
public:
    static void shellSort(vectorIt begin, vectorIt end);

    static int feedAnimals(std::vector<int> animals, std::vector<int> food);

    static char extraLetter(const std::string& a, const std::string& b);

    static std::vector<int> twoSum(std::vector<int>& arr, int target);

    static std::vector<std::vector<std::string> > groupAnagrams(const std::vector<std::string>& words);
};
#endif