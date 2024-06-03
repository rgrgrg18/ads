#include <gtest/gtest.h>
#include "sem2.1.h"
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// shell sort
struct ShellSort : public testing::Test {
  std::vector<int> arr;
  std::vector<int> arrShell;

  void SetUp(int sz, int p) {
    for (int i = 0; i < sz; ++i) {
      int currVal = rand() % p;
      arr.push_back(currVal);
      arrShell.push_back(currVal); 
    }
  }

  void TearDown() {}
};

void sortAndCompare(vector<int>& arr, vector<int>& arrShell) {
  std::sort(arr.begin(), arr.end());
  Solution::shellSort(arrShell.begin(), arrShell.end());
  EXPECT_EQ(arrShell, arr);
}

TEST_F(ShellSort, small_array) {
  for (int i = 0; i < 10; ++i) {
    ShellSort::SetUp(10, pow(10, 9));
    sortAndCompare(arr, arrShell);
  }
}
TEST_F(ShellSort, medium_arr_10_3) {
  for (int i = 0; i < 10; ++i) {
    ShellSort::SetUp(pow(10, 3), pow(10, 9));
    sortAndCompare(arr, arrShell);
  }
}
TEST_F(ShellSort, largest_arr_10_5) {
  for (int i = 0; i < 10; ++i) {
    ShellSort::SetUp(pow(10, 5), pow(10, 9));
    sortAndCompare(arr, arrShell);
  }
}

// feedAnimals
TEST(FeedAnimals, Test1) {
  ASSERT_EQ(Solution::feedAnimals({3, 4, 7}, {8, 1, 2}), 1);
}
TEST(FeedAnimals, Test2) {
  ASSERT_EQ(Solution::feedAnimals({3, 8, 1, 4}, {1, 1, 2}), 1);
}
TEST(FeedAnimals, Test3) {
  ASSERT_EQ(Solution::feedAnimals({1, 2, 2}, {7, 1}), 2);
}
TEST(FeedAnimals, Test4) {
  ASSERT_EQ(Solution::feedAnimals({8, 2, 3, 2}, {1, 4, 3, 8}), 3);
}

// extraLetter

std::string shuffle(std::string other) {
  std::string ans;
  for (int rightBorder = other.size(); rightBorder > 0; --rightBorder) {
    std::swap(other[rand() % rightBorder], other[rightBorder - 1]);
    ans.push_back(other[rightBorder - 1]);
  }
  return ans;
}

struct ExtraLetter: public testing::Test {
  string a;
  string b;
  char expectLetter;

  void SetUp(int size_A) {
    for (int i = 0; i < size_A; ++i) {
      a.push_back(rand() % 26 + 'a');
    }
    expectLetter = rand() % 26 + 'a';
    a.push_back(expectLetter);
    b = shuffle(a);
    a.pop_back();
  }

  void TearDown() {}
};

TEST_F(ExtraLetter, smallString) {
  ExtraLetter::SetUp(5);
  ASSERT_EQ(Solution::extraLetter(a, b), expectLetter) << testing::PrintToString(a) << "\n" << testing::PrintToString(b) << "\n";
}
TEST_F(ExtraLetter, mediumString) {
  ExtraLetter::SetUp(1000);
  ASSERT_EQ(Solution::extraLetter(a, b), expectLetter) << testing::PrintToString(a) << "\n" << testing::PrintToString(b) << "\n";
}
TEST_F(ExtraLetter, largestString) {
  ExtraLetter::SetUp(1000000);
  ASSERT_EQ(Solution::extraLetter(a, b), expectLetter) << testing::PrintToString(a) << "\n" << testing::PrintToString(b) << "\n";
}

// twoSum

struct TwoSum: public testing::Test {
  vector<int> arr;
  int target;

  void SetUp(int sz, int p = pow(10, 9)) {
    for (int i = 0; i < sz; ++i) {
      arr.push_back(rand() % p);
    }
  }

  void TearDown() {}
};

TEST_F(TwoSum, arr_exist) {
  int sz = 10;
  SetUp(10, 100);
  int target = arr[rand() % (sz / 2)] + arr[(sz / 2) + rand() % (sz / 2)];
  auto inx = Solution::twoSum(arr, target);

  ASSERT_FALSE(inx.size() == 0 || inx[0] == inx[1]) << testing::PrintToString(arr) << "\n" 
    << testing::PrintToString(target) << "\n" << testing::PrintToString(inx) << "\n";

  ASSERT_EQ(arr[inx[0]] + arr[inx[1]], target) << testing::PrintToString(arr) << "\n" 
    << testing::PrintToString(target) << "\n" << testing::PrintToString(inx) << "\n";
}

TEST_F(TwoSum, arr_not_exist) {
  int sz = 10;
  SetUp(10, 100);
  int target = 201;
  auto inx = Solution::twoSum(arr, target);

  ASSERT_TRUE(inx.size() == 0) << testing::PrintToString(arr) << "\n" 
    << testing::PrintToString(target) << "\n" << testing::PrintToString(inx) << "\n";
}


// groupAnagrams

bool comp(const vector<string>& first, const vector<string>& second) {
  if (first.size() > second.size()) return false;
  if (first.size() < second.size()) return true;
  int first_p = 0, second_p = 0;
  while (first_p < first.size()) {
    if (first[first_p] > second[second_p]) return false;
    ++first_p;
  }
  return true;
}

TEST(GroupAnagrams, Test1) {
  vector<vector<string> > ans = Solution::groupAnagrams({"eat","tea","tan","ate","nat","bat"});
  for (int i = 0; i < ans.size(); ++i) {
    std::sort(ans[i].begin(), ans[i].end());
  }
  std::sort(ans.begin(), ans.end(), comp);
  vector<vector<string>> expected = {{"bat"},{"nat","tan"},{"ate","eat","tea"}};
  ASSERT_EQ(ans, expected);
}

TEST(GroupAnagrams, Test2) {
  vector<vector<string> > ans = Solution::groupAnagrams({"won","now","aaa","ooo","ooo"});
  for (int i = 0; i < ans.size(); ++i) {
    std::sort(ans[i].begin(), ans[i].end());
  }
  std::sort(ans.begin(), ans.end(), comp);
  vector<vector<string>> expected = {{"aaa"},{"now", "won"}, {"ooo", "ooo"}};
  ASSERT_EQ(ans, expected);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc , argv);

  return RUN_ALL_TESTS();
}