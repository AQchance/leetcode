
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) {
                return false;
            }
            fast = fast->next;
            if (fast == nullptr) {
                return false;
            }
        } while (slow != fast);
        return true;
    }
};
