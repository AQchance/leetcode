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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) {
            return nullptr;
        }
        return helper(lists, 0, lists.size() - 1);
    }
    ListNode* helper(vector<ListNode*>& lists, int start, int end)
    {
        if (start == end) {
            return lists[start];
        }
        int mid = (start + end) / 2;
        ListNode* l1 = helper(lists, start, mid);
        ListNode* l2 = helper(lists, mid + 1, end);
        ListNode* head_node1 = new ListNode(0, l1);
        ListNode* head_node2 = new ListNode(0, l2);
        ListNode* p1 = head_node1;
        ListNode* p2 = head_node2;
        while (p2->next != nullptr) {
            if (p1->next == nullptr || p2->next->val < p1->next->val) {
                ListNode* tmp = p2->next;
                p2->next = tmp->next;
                tmp->next = p1->next;
                p1->next = tmp;
                p1 = tmp;
            } else {
                p1 = p1->next;
            }
        }
        l1 = head_node1->next;
        l2 = head_node2->next;
        delete head_node1;
        delete head_node2;
        return l1;
    }
};
