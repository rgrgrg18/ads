#include <vector>
#include <iostream>
#include <vector>

class Solution {
public:
    template <typename T>
    static void reverseArray(std::vector<T>& arr, int left, int right) {
        if (right <= left) return;
        int l = left, r = right;
        while (r > l) {
            std::swap(arr[l], arr[r]);
            ++l;
            --r;
        }
    }

    template <typename T>
    static void rotateArr(std::vector<T>& arr, int k) {
        reverseArray(arr, 0, arr.size() - 1);
        reverseArray(arr, 0, (k % arr.size()) - 1);
        reverseArray(arr, (k % arr.size()), arr.size() - 1);
    }

    template <typename T>
    static void rotateArrLc(std::vector<T>& arr, int k) {
        int inx = 0;
        int cnt = 0;
        int temp = arr[0];
        k = k % arr.size();
        int start = 0;
        while (cnt != arr.size()) {
            if (inx == start && cnt != 0) {
                inx++;
                start++;
                temp = arr[inx];
            }
            std::swap(temp, arr[(inx + k) % arr.size()]);
            inx = (inx + k) % arr.size();
            cnt++;
        }
    }

    template <typename T>
    static void mergeSortedArrays(std::vector<T>& arr1, std::vector<T>& arr2) {
        int p_1 = arr1.size() - arr2.size() - 1;
        int p_2 = arr2.size() - 1;
        int i = arr1.size() - 1;
        while (p_2 >= 0) {
            if (p_1 >= 0 && arr1[p_1] > arr2[p_2]) {
                arr1[i--] = arr1[p_1--];
            } else {
                arr1[i--] = arr2[p_2--];
            }
        }
    }

    template <typename T>
    static void evenFirst(std::vector<T>& arr) {
        int first_p = 0, second_p = 0;
        while (second_p < arr.size()) {
            if (arr[second_p] % 2 == 0) {
                std::swap(arr[first_p], arr[second_p]);
                ++first_p;
            }
            ++second_p;
        }
    }

    template<typename T>
    static void nullToEnd(std::vector<T>& arr) {
        int first_p = 0, second_p = arr.size() - 1;
        while (arr[second_p] == 0) --second_p;
        while (first_p < second_p) {
            if (arr[first_p] == 0) {
                std::swap(arr[first_p], arr[second_p]);
                --second_p;
            }
            ++first_p;
        }
    }
};

template <typename T>
void printArray(std::vector<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

