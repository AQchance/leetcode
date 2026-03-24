
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* head_node = new ListNode;
        head_node->next = head;
        ListNode *p = head_node, *q = head_node;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        head = head_node->next;
        delete head_node;
        return head;
    }
};
