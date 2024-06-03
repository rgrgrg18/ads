#include <iostream>
#include <vector>


template <typename T>
class ListNode {
public:
    T val;
    ListNode* next = nullptr;

    ListNode() = default;
    ListNode(int val): val(val) {};    
};

template <typename T>
class List {
public:

    ListNode<T>* head = nullptr;
    ListNode<T>* tail = nullptr;

    void push_front(int val) {
        if (head == nullptr) {
            head = new ListNode<T>(val);
            tail = head;
            return;
        } 
        ListNode<T>* temp = new ListNode<T>(val);
        temp->next = head;
        head = temp;
    }

    void push_back(int val) {
        if (head == nullptr) {
            head = new ListNode<T>(val);
            tail = head;
            return;
        }
        if (head == tail) {
            head->next = new ListNode<T>(val);
            tail = head->next;
            return;
        }
        tail->next = new ListNode<T>(val);
        tail = tail->next;
    }

    List() = default;
    explicit List(int val): head(new ListNode<T>(val)), tail(head) {};
    List(std::initializer_list<int> values) {
        for (auto elem : values) {
            push_back(elem);
        }
    };
};


class Solution {
public:
    template <typename T>
    static bool isCyclic(List<T>& list) {
        if (list.head == nullptr) return false;
        ListNode<T>* slow = list.head;
        ListNode<T>* faster = list.head->next;
        while (slow != nullptr && faster != nullptr) {
            if (slow == faster) return true;
            slow = slow->next;
            faster = faster->next;
            if (faster != nullptr) faster = faster->next;
        }
        return false;
    }

    template <typename T>
    static void reverseList(List<T>& list) {
        if (list.head == nullptr) return;
        ListNode<T>* prev = nullptr;
        ListNode<T>* curr = list.head;
        while (curr != nullptr) {
            ListNode<T>* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        list.head = prev;
    }

    template <typename T>
    static ListNode<T>* midOfList(List<T>& list) {
        ListNode<T>* slow = list.head;
        ListNode<T>* fast = list.head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }  

    template <typename T>
    static void delNode(List<T>& list, int val) {
        ListNode<T>* dummy = new ListNode<T>();
        dummy->next = list.head;
        ListNode<T>* prev = dummy;
        ListNode<T>* curr = list.head;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            curr = curr->next;
            prev = prev->next;
        }
    } 

    template <typename T>
    static void mergeSortedLists(List<T>& list1, List<T>& list2) {
        if (list1.head == nullptr) {
            list1.head = list2.head;
            list2.head = nullptr;
            return;
        } else if (list2.head == nullptr) return;
    
        ListNode<T>* curr = nullptr;
        ListNode<T>* first_p = list1.head;
        ListNode<T>* second_p = list2.head;
        if (list1.head->val < list2.head->val) {
            curr = list1.head;
            first_p = first_p->next;
        } else {
            curr = list2.head;
            list1.head = curr;
            second_p = second_p->next;
        }

        while (first_p != nullptr && second_p != nullptr) {
            if (first_p->val >= second_p->val) {
                curr->next = second_p;
                second_p = second_p->next;
            } else {
                curr->next = first_p;
                first_p = first_p->next;
            }
            curr = curr->next;
        }

        auto go_to_end = [&](auto& it){
            while (it != nullptr) {
                curr->next = it;
                it = it->next;
                curr = curr->next;
            }
        };
        go_to_end(first_p);
        go_to_end(second_p);

        // while (second_p != nullptr) {
        //     curr->next = second_p;
        //     second_p = second_p->next;
        //     curr = curr->next;
        // }

        list2.head = nullptr;

    }

};

template <typename T>
static void printList(List<T>& list) {
    if (Solution::isCyclic(list)) {
        std::cout << "It's a cyclic list";
    } else {
        ListNode<T>* head = list.head;
        while (head != nullptr) {
            std::cout << head->val << " ";
            head = head->next;
        }
    }
    std::cout << "\n";
}


