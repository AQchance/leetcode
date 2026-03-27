#include <queue>

using namespace std;

class MyStack {
public:
    MyStack()
    {
    }

    void push(int x)
    {
        my_queue.push(x);
    }

    int pop()
    {
        std::queue<int> tmp;
        int num = 0;
        while (!my_queue.empty()) {
            num = my_queue.front();
            my_queue.pop();
            if (!my_queue.empty()) {
                tmp.push(num);
            }
        }
        while (!tmp.empty()) {
            my_queue.push(tmp.front());
            tmp.pop();
        }
        return num;
    }

    int top()
    {
        return my_queue.back();
    }

    bool empty()
    {
        return my_queue.empty();
    }

private:
    std::queue<int> my_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
