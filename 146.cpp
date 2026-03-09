#include <filesystem>
#include <unordered_map>

using namespace std;

struct MyListNode {
    struct MyListNode* next;
    struct MyListNode* prev;
    int val;
    int key;
};

class LRUCache {
public:
    LRUCache(int capacity)
    {
        // 因为是双向链表，因此需要虚拟头节点以及虚拟尾节点两个冗余节点
        cnt = 0;
        this->capacity = capacity;
        head = new MyListNode;
        tail = new MyListNode;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }

    int get(int key)
    {
        if (address_map.find(key) != address_map.end()) {
            // 这个时候找到了节点
            MyListNode* node = address_map.at(key);
            move_to_head(node);
            return node->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (address_map.find(key) != address_map.end()) {
            // 这个时候说明已经找到了节点了，这个节点就在双向链表里面
            MyListNode* node = address_map.at(key);
            move_to_head(node);
            node->val = value;
        } else {
            cnt++;
            // 这个时候说明没有找到这个节点，现在需要我们手动添加这个节点。
            MyListNode* node = new MyListNode;
            address_map[key] = node;
            node->key = key;
            node->val = value;
            add_to_head(node);
            if (cnt > capacity) {
                MyListNode* removed = remove_tail();
                address_map.erase(removed->key);
                cnt--;
            }
        }
    }
    void add_to_head(MyListNode* tmp)
    {
        tmp->next = head->next;
        head->next->prev = tmp;
        tmp->prev = head;
        head->next = tmp;
    }
    void remove_node(MyListNode* tmp)
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    MyListNode* remove_tail()
    {
        MyListNode* tmp = tail->prev;
        remove_node(tmp);
        return tmp;
    }
    void move_to_head(MyListNode* tmp)
    {
        remove_node(tmp);
        add_to_head(tmp);
    }

private:
    std::unordered_map<int, MyListNode*> address_map;
    MyListNode* head = nullptr;
    MyListNode* tail = nullptr;
    int cnt;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
