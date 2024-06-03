#include "sem2.2.h"
#include <iostream>
#include <queue>

using namespace std;

// 1
TreeNode* Solution::makeTree(const vector<int>& arr, int i) {
    if (i >= arr.size()) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = makeTree(arr, 2 * i + 1);
    root->right = makeTree(arr, 2 * i + 2);
    return root;
}

// 2
bool Solution::isSymmetricSubtrees(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    if (left->val != right->val) return false;
    return isSymmetricSubtrees(left->left, right->right) && isSymmetricSubtrees(left->right, right->left);
}

bool Solution::isSymmetricTree(TreeNode* root) {
    return isSymmetricSubtrees(root, root);
}

//3
// dfs
int Solution::minHeightDFS(TreeNode* root) {
    if (root == nullptr) return 0;
    return min(minHeightDFS(root->left), minHeightDFS(root->right)) + 1;
}

// bfs
int Solution::minHeightBFS(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> nodes;
    nodes.push(root);
    int currLevel = 1;
    while (true) {
        int sz = nodes.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* currNode = nodes.front();
            nodes.pop();
            if (currNode->left == nullptr || currNode->right == nullptr) return currLevel;
            nodes.push(currNode->left);
            nodes.push(currNode->right);
        }
        ++currLevel;
    }
}

// 4
long long Solution::maxMult(TreeNode* root) {
    TreeNode* minElement = root;
    while (minElement->left) minElement = minElement->left;
    TreeNode* maxElement = root;
    while (maxElement->right) maxElement = maxElement->right;
    return maxElement->val * minElement->val;
}

// 5
bool Solution::isSameTrees(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr && tree2 == nullptr) return true;
    if (tree1 == nullptr || tree2 == nullptr) return false;
    if (tree1->val != tree2->val) return false;
    return isSameTrees(tree1->left, tree2->left) && isSameTrees(tree1->right, tree2->right); 
}

// 6
long long Solution::cntTrees(int n) {
    vector<int> dp(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        int left = 0, right = i - 1;
        while (right > left) {
            dp[i] += dp[right] * dp[left] * 2;
            --right;
            ++left;
        }
        if (i % 2 != 0) {
            dp[i] += dp[right] * dp[right];
        }
    }
    return dp[n];
}
