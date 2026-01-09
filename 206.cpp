#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (nullptr == head) {
            return head;
        }
        ListNode* tail = head;
        while (nullptr != tail->next) {
            ListNode* p = tail->next;
            tail->next = p->next;
            p->next = head;
            head = p;
        }
        return head;
    }
};
