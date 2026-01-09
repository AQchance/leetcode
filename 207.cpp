#include <algorithm>
#include <iostream>
#include <linux/limits.h>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

// NOTE: 自己的方案
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::set<int> s1, s2, s3, s4;
        int** graph = new int*[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = new int[numCourses] { 0 };
        }
        for (auto& item : prerequisites) {
            int from_node = item[1];
            int to_node = item[0];
            s1.insert(from_node);
            s2.insert(to_node);
            graph[from_node][to_node] = 1;
        }
        // s3中就是入度为0的所有节点了
        std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.begin()));
        std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s4, s4.begin()));
        int node_cnt = s4.size();
        int cnt = 0;
        while (!s3.empty()) {
            int node = *s3.begin();
            s3.erase(s3.begin());
            cnt++;
            for (int i = 0; i < numCourses; i++) {
                if (graph[node][i] == 1) {
                    graph[node][i] = 0;
                    bool flag = true;
                    for (int j = 0; j < numCourses; j++) {
                        if (graph[j][i] == 1) {
                            flag = false;
                            break;
                        }
                    }
                    // 入度变成了0,可以加入s3了
                    if (flag) {
                        s3.insert(i);
                    }
                }
            }
        }
        if (cnt == node_cnt) {
            return true;
        } else {
            return false;
        }
    }
};
