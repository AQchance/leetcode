#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

struct Info {
    TreeNode* node;
    int level;
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        std::stack<Info> st;
        std::queue<Info> q;
        q.push(Info(root, 0));
        int level = 0;
        while (!q.empty()) {
            TreeNode* tmp = q.front().node;
            level = q.front().level;
            st.push(q.front());
            q.pop();
            if (tmp->right != nullptr) {
                q.push(Info(tmp->right, level + 1));
            }
            if (tmp->left != nullptr) {
                q.push(Info(tmp->left, level + 1));
            }
        }
        level = st.top().level;
        while (!st.empty()) {
            std::vector<int> level_ans;
            while (!st.empty() && st.top().level == level) {
                TreeNode* tmp = st.top().node;
                level_ans.push_back(tmp->val);
                st.pop();
            }
            ans.push_back(level_ans);
            level--;
        }
        return ans;
    }
};
