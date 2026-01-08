#include <vector>

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

// NOTE: 这里是直接使用的额外的空间来存储
// 也可以找到后面一半的链表的位置，然后原地反转后一半链表，然后使用双指针来判断是否是回文链表
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        bool ans = true;
        if (head == nullptr) {
            return true;
        }
        std::vector<int> reg;
        while (head) {
            reg.push_back(head->val);
            head = head->next;
        }
        if (reg.size() == 1) {
            return true;
        }
        size_t i = 0, j = reg.size() - 1;
        while (i < j) {
            if (reg[i] != reg[j]) {
                ans = false;
            }
            i++;
            j--;
        }
        return ans;
    }
};
