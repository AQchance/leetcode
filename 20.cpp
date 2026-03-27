#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        std::stack<char> my_stack;
        bool flag = true;
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                my_stack.push(ch);
            } else {
                if (my_stack.empty()) {
                    flag = false;
                    break;
                }
                if (ch == ')') {
                    if (my_stack.top() == '(') {
                        my_stack.pop();
                    } else {
                        flag = false;
                        break;
                    }
                } else if (ch == ']') {
                    if (my_stack.top() == '[') {
                        my_stack.pop();
                    } else {
                        flag = false;
                        break;
                    }
                } else if (ch == '}') {
                    if (my_stack.top() == '{') {
                        my_stack.pop();
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag == true && !my_stack.empty()) {
            flag = false;
        }
        return flag;
    }
};
