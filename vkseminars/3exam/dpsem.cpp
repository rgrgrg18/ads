#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {    
public:    

    // the number of sequences that do not contain two consecutive 1
    static int countSeq(int n) {
        std::vector<size_t> dp = {1, 2, 4};

        for (int i = 3; i <= n; ++i) {
            dp.push_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
        }
        
        return dp[n];
    }

    // longest increasing subarray
    static int longestIncreasingSubarr(std::vector<int>& arr) {
        if (arr.size() < 2) return arr.size();

        int currCnt = 1;
        int ansCnt = 1;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                ++currCnt;
            } else {
                currCnt = 1;
            }
            ansCnt = max(ansCnt, currCnt);
        }

        return ansCnt;
    }

    // pascal triangle
    static std::vector<std::vector<int> > pascalTriangle(int n) {
        if (n <= 0) return {};

        std::vector<std::vector<int> > dp(n, vector<int>(1, 1));

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
            }
            dp[i].push_back(1);
        }

        return dp;
    }

    static void push(std::vector<int>& from, std::vector<int>& to) {
        for (auto& elem : from) to.push_back(elem);
    }

    // max sum path in binary tree
    static pair<int, std::vector<int>> maxPath(TreeNode* root, std::vector<int>& ansPath, int& ansSum) {
        if (!root) return {0, {}};
        pair<int, std::vector<int>> left = maxPath(root->left, ansPath, ansSum);
        int leftSum = left.first;
        vector<int> leftPath = left.second;
    
        pair<int, std::vector<int>> right = maxPath(root->right, ansPath, ansSum);
        int rightSum = right.first;
        vector<int> rightPath = right.second;

        std::vector<int> currPath = {};
        int currSum = root->val;

        if (leftSum > rightSum) {
            push(leftPath, currPath);
            currSum += leftSum;
        } else {
            push(rightPath, currPath);
            currSum += rightSum;
        }
        currPath.push_back(root->val);

        if (leftSum + root->val + rightSum > ansSum) {
            ansSum = leftSum + root->val + rightSum;
            ansPath = {};
            push(leftPath, ansPath);
            ansPath.push_back(root->val);
            push(rightPath, ansPath);
        }

        return {currSum, currPath};
    }

    // best time to buy and sell stocks
    static size_t bestTime(std::vector<int>& arr) {
        size_t ansProfit = 0;
        int buyInx = 0;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[buyInx] > ansProfit) {
                ansProfit = arr[i] - arr[buyInx];
            }
            if (arr[buyInx] > arr[i]) buyInx = i;
        }

        return ansProfit;
    }

    // leetcode 322
    static int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (auto coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if (dp[amount] != 10001) return dp[amount];
        return -1;
    }

};