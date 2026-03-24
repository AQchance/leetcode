#include <vector>

using namespace std;

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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* head_node = new ListNode;
        head_node->next = head;
        ListNode* p = head_node;
        while (p->next != nullptr) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        p = head_node->next;
        delete head_node;
        return p;
    }
};
