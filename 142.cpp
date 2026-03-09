#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
            if (fast == nullptr) {
                return nullptr;
            }
        } while (slow != fast);
        ListNode* ptr = head;
        while (slow != ptr) {
            slow = slow->next;
            ptr = ptr->next;
        }
        return slow;
    }
};
