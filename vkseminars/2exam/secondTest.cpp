#include <gtest/gtest.h>
#include "sem2.2.h"
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int p = pow(10, 9);

// MakeTree
struct MakeTree: public testing::Test {
    vector<int> arr;
    void SetUp(int sz) {
        for (int i = 0; i < sz; ++i) {
            arr.push_back(rand() % p);
        }
    }

    void TearDown() {}
};

vector<int> levelTraverse(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode == nullptr) return ans;
            ans.push_back(currNode->val);
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return ans;
}

TEST_F(MakeTree, smallTree) {
    for (int i = 0; i < 10; ++i) {
        SetUp(10);
        TreeNode* root = Solution::makeTree(arr);
        vector<int> ans = levelTraverse(root);
        ASSERT_EQ(ans, arr);
    }
}
TEST_F(MakeTree, mediumTree) {
    for (int i = 0; i < 10; ++i) {
        SetUp(1000);
        TreeNode* root = Solution::makeTree(arr);
        vector<int> ans = levelTraverse(root);
        EXPECT_EQ(ans, arr);
    }
}
TEST_F(MakeTree, largeTree) {
    for (int i = 0; i < 5; ++i) {
        SetUp(1000000);
        TreeNode* root = Solution::makeTree(arr);
        vector<int> ans = levelTraverse(root);
        EXPECT_EQ(ans, arr);
    }
}


// isSymmetricTree
TEST(IsSymmetric, Test1) {
    TreeNode* root = Solution::makeTree({1, 2, 2, 3, 4, 4, 3});
    ASSERT_EQ(Solution::isSymmetricTree(root), true);
}
TEST(IsSymmetric, Test2) {
    TreeNode* root = Solution::makeTree({1, 2, 2, 5, 4, 4, 3});
    ASSERT_EQ(Solution::isSymmetricTree(root), false);
}
TEST(IsSymmetric, Test3) {
    TreeNode* root = Solution::makeTree({1, 2, 2, 3, 4, 4});
    ASSERT_EQ(Solution::isSymmetricTree(root), false);
}

// minHeightDFS/BFS
TEST(MinHeight, Test1) {
    TreeNode* root = Solution::makeTree({11, 8, 16, 2, 9, 6, 7, 9});
    ASSERT_EQ(Solution::minHeightBFS(root), 3);
    ASSERT_EQ(Solution::minHeightDFS(root), 3);
}
TEST(MinHeight, Test2) {
    TreeNode* root = Solution::makeTree({11, 8, 16, 2, 2});
    ASSERT_EQ(Solution::minHeightBFS(root), 2);
    ASSERT_EQ(Solution::minHeightDFS(root), 2);
}

TreeNode* arrToBinTree(const vector<int>& arr, int left, int right) {
    if (left > right) return nullptr;
    int inx = (left + right) / 2;
    TreeNode* newNode = new TreeNode(arr[inx]);
    newNode->left = arrToBinTree(arr, (left + right) / 2 + 1, right);
    newNode->right = arrToBinTree(arr, left, inx - 1);
    return newNode;
}

// maxMult
struct MaxMult: public testing::Test {
    TreeNode* root = nullptr;

    int minVal, maxVal;

    void SetUp(int sz) {
        vector<int> helpArr;
        for (int i = 0; i < sz; ++i) {
            helpArr.push_back(rand() % p);
        }
        std::sort(helpArr.begin(), helpArr.end());
        minVal = helpArr[0];
        maxVal = helpArr[helpArr.size() - 1];

        root = arrToBinTree(helpArr, 0, sz - 1);
    }

    void TearDown() {}

};

TEST_F(MaxMult, smallTree) {
    SetUp(10);
    ASSERT_EQ(Solution::maxMult(root), minVal*maxVal);
}
TEST_F(MaxMult, largeTree) {
    SetUp(100000);
    ASSERT_EQ(Solution::maxMult(root), minVal*maxVal);
}


// isSameTrees
struct IsSame: public testing::Test {
    vector<int> arr;

    void SetUp(int sz) {
        arr.clear();
        for (int i = 0; i < sz; ++i) {
            arr.push_back(rand() % p);
        }
    }
};

TEST_F(IsSame, same) {
    for (int i = 10; i < 100000; i *= 10) {
        SetUp(i);
        vector<int> arr1 = arr;
        TreeNode* root0 = Solution::makeTree(arr);
        TreeNode* root1 = Solution::makeTree(arr1);
        ASSERT_EQ(Solution::isSameTrees(root0, root1), true);
    }
}
TEST_F(IsSame, notSame) {
    for (int i = 10; i < 100000; i *= 10) {
        SetUp(i);
        vector<int> arr1 = arr;
        if (rand() % 2 == 0) arr1.push_back(rand() % p);
        
        arr1[rand() % arr1.size()] = rand() % p; 
        TreeNode* root0 = Solution::makeTree(arr);
        TreeNode* root1 = Solution::makeTree(arr1);
        ASSERT_EQ(Solution::isSameTrees(root0, root1), false);
    }
}


// cntTrees

TEST(cntTrees, test) {
    unordered_map<int, long long> ans = {
        {1,  1},
        {2,  2},
        {3,  5},
        {4,  14},
        {5,  42},
        {6,  132},
        {7,  429},
        {8,  1430}, 
        {9,  4862},
        {10, 16796},
        {11, 58786},
        {12, 208012},
        {13, 742900},
        {14, 2674440},
        {15, 9694845},
        {16, 35357670},
        {17, 129644790},
        {18, 477638700},
        {19, 1767263190}
    };
    for (int i = 1; i <= 19; ++i) {
        ASSERT_EQ(Solution::cntTrees(i), ans[i]);
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc , argv);

    return RUN_ALL_TESTS();
}