#include <stack>
#include <vector>

using namespace std;

class MyQueue {
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        my_stack.push(x);
    }

    int pop()
    {
        std::stack<int> tmp;
        while (!my_stack.empty()) {
            tmp.push(my_stack.top());
            my_stack.pop();
        }
        int num = tmp.top();
        tmp.pop();
        while (!tmp.empty()) {
            my_stack.push(tmp.top());
            tmp.pop();
        }
        return num;
    }

    int peek()
    {
        std::stack<int> tmp;
        while (!my_stack.empty()) {
            tmp.push(my_stack.top());
            my_stack.pop();
        }
        int num = tmp.top();
        while (!tmp.empty()) {
            my_stack.push(tmp.top());
            tmp.pop();
        }
        return num;
    }

    bool empty()
    {
        return my_stack.empty();
    }

private:
    std::stack<int> my_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
