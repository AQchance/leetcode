#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n)
    {
        std::unordered_set<int> my_set;
        bool flag = true;
        while (n != 1) {
            if (my_set.contains(n)) {
                flag = false;
                break;
            }
            my_set.insert(n);
            int sum = 0;
            while (n > 0) {
                int num = n % 10;
                sum += num * num;
                n /= 10;
            }
            n = sum;
        }
        return flag;
    }
};
