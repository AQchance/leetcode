#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        std::stack<int> tmp;
        for (auto item : tokens) {
            if ('0' <= item[0] && item[0] <= '9' || item[0] == '-' && item.size() > 1) {
                int num = std::stoi(item);
                tmp.push(num);
            } else {
                if (item[0] == '+') {
                    int num2 = tmp.top();
                    tmp.pop();
                    int num1 = tmp.top();
                    tmp.pop();
                    tmp.push(num1 + num2);
                } else if (item[0] == '-') {
                    int num2 = tmp.top();
                    tmp.pop();
                    int num1 = tmp.top();
                    tmp.pop();
                    tmp.push(num1 - num2);
                } else if (item[0] == '*') {
                    int num2 = tmp.top();
                    tmp.pop();
                    int num1 = tmp.top();
                    tmp.pop();
                    tmp.push(num1 * num2);
                } else if (item[0] == '/') {
                    int num2 = tmp.top();
                    tmp.pop();
                    int num1 = tmp.top();
                    tmp.pop();
                    tmp.push(num1 / num2);
                }
            }
        }
        return tmp.top();
    }
};
