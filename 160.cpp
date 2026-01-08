#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

// NOTE: 使用哈希表存储链表A的节点，然后遍历链表B，找到第一个在哈希表中出现的节点即为交点
// 时间复杂度: O(N + M)，空间复杂度: O(N)
// 这是第一个方法，但不是最优解法
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
//     {
//         std::unordered_set<ListNode*> nodes_set;
//         ListNode* tmpA = headA;
//         while (tmpA) {
//             nodes_set.insert(tmpA);
//             tmpA = tmpA->next;
//         }
//         ListNode* tmpB = headB;
//         while (tmpB) {
//             if (nodes_set.find(tmpB) != nodes_set.end()) {
//                 break;
//             }
//             tmpB = tmpB->next;
//         }
//         return tmpB;
//     }
// };

// 优化方法：双指针法
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while (ptrA != ptrB) {
            if (ptrA == nullptr) {
                ptrA = headB;
            } else {
                ptrA = ptrA->next;
            }

            if (ptrB == nullptr) {
                ptrB = headA;
            } else {
                ptrB = ptrB->next;
            }
        }
        return ptrA;
    }
};
