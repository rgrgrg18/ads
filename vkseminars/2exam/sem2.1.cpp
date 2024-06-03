#include "sem2.1.h"

using vectorIt = std::vector<int>::iterator;

void Solution::shellSort(vectorIt begin, vectorIt end)
{
    std::vector<int> step = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int gapInx = step.size() - 1;
    while (gapInx >= 0)
    {
        int gap = step[gapInx];
        for (vectorIt currPos = begin + gap; currPos < end; ++currPos)
        {
            vectorIt left = currPos - gap, right = currPos;
            while (left >= begin && (*(right)) < (*(left)))
            {
                std::swap(*(right), *(left));
                right = left;
                left -= gap;
            }
        }
        --gapInx;
    }
}

int Solution::feedAnimals(std::vector<int> animals, std::vector<int> food) {
    shellSort(food.begin(), food.end());
    shellSort(animals.begin(), animals.end());
    int first = food.size() - 1;
    int second = animals.size() - 1;
    int ans = 0;
    while (first >= 0 && second >= 0) {
        while (second >= 0 && animals[second] > food[first]) --second;
        if (second >= 0) {
            ++ans;
            --second;
        }
        --first;
    }
    return ans;
}

char Solution::extraLetter(const std::string& a, const std::string& b) {
    std::vector<int> cnt(26, 0);
    for (int i = 0; i < a.size(); ++i) {
        --cnt[a[i] - 'a'];
        ++cnt[b[i] - 'a'];
    }
    ++cnt[b[b.size() - 1] - 'a'];
    for (int i = 0; i < cnt.size(); ++i) {
        if (cnt[i] != 0) return i + 'a';
    }
}

std::vector<int> Solution::twoSum(std::vector<int>& arr, int target) {
    std::unordered_map<int, int> prev;
    for (int i = 0; i < arr.size(); ++i) {
        auto it = prev.find(target - arr[i]);
        if (it != prev.end()) {
            return {it->second, i};
        } 
        prev[arr[i]] = i;
    }
    return {};
}

std::vector<std::vector<std::string> > Solution::groupAnagrams(const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> hashInx;
    std::vector<std::vector<std::string> > ans;
    for (int i = 0; i < words.size(); ++i) {
        std::string word = words[i];
        std::sort(word.begin(), word.end());
        auto it = hashInx.find(word);
        if (it == hashInx.end()) {
            hashInx[word] = ans.size();
            ans.push_back({});
        } 
        ans[hashInx[word]].push_back(words[i]);
    }
    return ans;
}

