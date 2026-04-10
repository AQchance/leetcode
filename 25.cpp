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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* head_node = new ListNode(0, head);
        ListNode* pre = head_node;
        while (pre->next != nullptr) {
            int cnt = 0;
            ListNode* head_tmp = pre->next;
            ListNode* next_pre = pre;
            while (next_pre->next != nullptr && cnt < k) {
                cnt++;
                next_pre = next_pre->next;
            }
            if (cnt < k) {
                break;
            }
            ListNode* next_head = next_pre->next;
            next_pre->next = nullptr;
            pre->next = reverse_list(head_tmp);
            head_tmp->next = next_head;
            pre = head_tmp;
        }
        head = head_node->next;
        delete head_node;
        return head;
    }
    ListNode* reverse_list(ListNode* head)
    {
        if (nullptr == head) {
            return nullptr;
        }
        ListNode* head_node = new ListNode(0, nullptr);
        ListNode* p = head;
        while (p != nullptr) {
            ListNode* tmp = p;
            p = p->next;
            tmp->next = head_node->next;
            head_node->next = tmp;
        }
        head = head_node->next;
        delete head_node;
        return head;
    }
};
