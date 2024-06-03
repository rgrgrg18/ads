#ifndef _sem_2_2_h_
#define _sem_2_2_h_
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int val): val(val) {}

};

class Solution {
    static bool isSymmetricSubtrees(TreeNode* left, TreeNode* right);
public:
    static TreeNode* makeTree(const vector<int>& arr, int i = 0);

    static bool isSymmetricTree(TreeNode* root);

    static int minHeightDFS(TreeNode* root);

    static int minHeightBFS(TreeNode* root);

    static long long maxMult(TreeNode* root);

    static bool isSameTrees(TreeNode* tree1, TreeNode* tree2);

    static long long cntTrees(int n);

};

#endif