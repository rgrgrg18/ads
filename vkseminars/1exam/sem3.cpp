#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

class Solution {
public:
    static int copyTime(int n, int x, int y) {
        int l = 0, r = (n - 1) * std::max(x, y);

        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (mid / x + mid / y >= (n - 1)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r + std::min(x, y);
    }

    static bool isSubsequeceQueue(const std::string& str1, const std::string& str2) {
        std::queue<char> q;
        for (auto elem : str1) {
            q.push(elem);
        }
        for (auto elem : str2) {
            if (elem == q.front()) {
                q.pop();
            }
        }
        return q.empty();
    }

    static bool isSubsequecePointers(const std::string& str1, const std::string& str2) {
        int first_p = 0;
        for (int second_p = 0; second_p < str2.size(); ++second_p) {
            if (first_p == str1.size()) return true;
            if (str1[first_p] == str2[second_p]) first_p++;
        }
        if (first_p == str1.size()) return true;
        return false;
    }

    static int binarySearchSqrt(int x) {
        int l = 0, r = x + 1;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (mid * mid > x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }

    static bool isPalindromeStack(const std::string& str) {
        std::stack<char> stack;
        for (int i = 0; i < str.size() / 2; ++i) {
            stack.push(str[i]);
        }
        for (int i = (str.size() + 1) / 2; i < str.size(); ++i) {
            if (stack.top() != str[i]) return false;
            stack.pop();
        }
        return true;
    }

    static bool isPalindromePointers(const std::string& str) {
        int left = 0, right = str.size() - 1;
        while (left < str.size() / 2 && right >= (str.size() + 1) / 2) {
            if (str[left] != str[right]) return false;
            ++left;
            --right;
        }
        return true;
    }

    static void removeDuplicates(std::string& str) {
        std::string stack;
        for (auto elem : str) {
            if (elem == stack[stack.size() - 1]) {
                stack.pop_back();
            } else {
                stack.push_back(elem);
            }
        }
        str = "";
        for (auto elem : stack) {
            str.push_back(elem);
        }
    }


};

int main() {


    /*
    std::cout << "type task number: ";
    int task; std::cin >> task;
    
    int n, x, y, k;
    std::string str, str1, str2;
    switch(task) {
        case 1:
            std::cout << "type n, x, y: ";
            int n, x, y; std::cin >> n >> x >> y;
            std::cout << Solution::copyTime(n, x, y);
            break;
        case 2:
            std::cout << "type strings: ";
            std::cin >> str1 >> str2;
            std::cout << Solution::isSubsequeceQueue(str1, str2);
            break;
        case 3:
            std::cout << "type strings: ";
            std::cin >> str1 >> str2;
            std::cout << Solution::isSubsequecePointers(str1, str2);
            break;
        case 4:
            std::cout << "type the n: ";
            std::cin >> k;
            std::cout << Solution::binarySearchSqrt(k);
            break;
        case 5:
            std::cout << "type string: ";
            std::cin >> str;
            std::cout << Solution::isPalindromeStack(str);
            break;
        case 6:
            std::cout << "type string: ";
            std::cin >> str;
            std::cout << Solution::isPalindromePointers(str);
            break;
        case 7:
            std::cout << "type string: ";
            std::cin >> str;
            Solution::removeDuplicates(str);
            std::cout << str;
            break;
    }

    */

    
    std::cout << "1. copyTime\n";
    {
        int n = 10, x = 1, y = 2;
        std::cout << Solution::copyTime(n, x, y) << "\n";
        n = 20; x = 3; y = 2;
        std::cout << Solution::copyTime(n, x, y) << "\n";
    }

    std::cout << "2.isSubsequeceQueue\n";
    {  
        std::string str1 = "uio", str2 = "quefio";
        std::cout << Solution::isSubsequeceQueue(str1, str2);
    }

    std::cout << "3.isSubsequecePointers\n";
    {
        std::string str1 = "uio", str2 = "quefio";
        std::cout << Solution::isSubsequecePointers(str1, str2);
    }

    std::cout << "4.binarySearchSqrt\n";
    {
        int x = 0;
        std::cout << Solution::binarySearchSqrt(x) << "\n";
        x = 1;
        std::cout << Solution::binarySearchSqrt(x) << "\n";
        x = 15;
        std::cout << Solution::binarySearchSqrt(x) << "\n";
        x = 16;
        std::cout << Solution::binarySearchSqrt(x) << "\n";
    }

    std::cout << "5.isPalindromeStack\n";
    {
        std::string str = "abba";
        std::cout << Solution::isPalindromeStack(str) << "\n";
        str = "abab";
        std::cout << Solution::isPalindromeStack(str) << "\n";
        str = "ababa";
        std::cout << Solution::isPalindromeStack(str) << "\n";
    }
    
    std::cout << "6.isPalindromePointers\n";
    {
        std::string str = "abba";
        std::cout << Solution::isPalindromePointers(str) << "\n";
        str = "abab";
        std::cout << Solution::isPalindromePointers(str) << "\n";
        str = "ababa";
        std::cout << Solution::isPalindromePointers(str) << "\n";
    }
    

    std::cout << "7.removeDuplicates\n";
    {
        std::string str = "cdffd";
        Solution::removeDuplicates(str);
        std::cout << str << "\n";
        str = "uioouiouuo";
        str = "uioooouiouuuo";
        Solution::removeDuplicates(str);
        std::cout << str << "\n";
    }
    
}
