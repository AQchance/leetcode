#include <ios>
#include <queue>

using namespace std;

class MedianFinder {
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left_heap.empty()) {
            right_heap.push(num);
            if (right_heap.size() > left_heap.size() + 1) {
                left_heap.push(right_heap.top());
                right_heap.pop();
            }
            return;
        }
        int left_top = left_heap.top();
        if (num <= left_top) {
            left_heap.push(num);
            if (left_heap.size() > right_heap.size()) {
                right_heap.push(left_heap.top());
                left_heap.pop();
            }
        } else {
            right_heap.push(num);
            if (right_heap.size() > left_heap.size() + 1) {
                left_heap.push(right_heap.top());
                right_heap.pop();
            }
        }
    }

    double findMedian()
    {
        int size = left_heap.size() + right_heap.size();
        double ans = right_heap.top();
        if (size % 2 == 0) {
            ans += left_heap.top();
            return ans / 2;
        }
        return ans;
    }

private:
    std::priority_queue<int> left_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
