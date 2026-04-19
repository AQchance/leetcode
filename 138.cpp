#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> old_new_map;
        std::unordered_map<Node*, Node*> new_old_map;
        Node* tmp = head;
        Node* head_node = new Node(0);
        Node* tail = head_node;
        while (tmp != nullptr) {
            Node* new_node = new Node(tmp->val);
            tail->next = new_node;
            old_new_map[tmp] = new_node;
            new_old_map[new_node] = tmp;

            tail = new_node;
            tmp = tmp->next;
        }
        tmp = head_node->next;
        while (tmp != nullptr) {
            Node* old_node = new_old_map[tmp];
            if (old_node->random != nullptr) {
                tmp->random = old_new_map[old_node->random];
            }
            tmp = tmp->next;
        }
        tmp = head_node->next;
        delete head_node;
        return tmp;
    }
};
