
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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* head_node = new ListNode;
        head_node->next = head;
        ListNode* p = head_node;
        ListNode* q = head_node->next;
        while (q != nullptr) {
            if (q->next == nullptr) {
                // 只剩下奇数个元素
                break;
            }
            ListNode* node1 = p->next;
            ListNode* node2 = q->next;
            p->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            p = p->next->next;
            q = p->next;
        }
        head = head_node->next;
        delete head_node;
        return head;
    }
};
