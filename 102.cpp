#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> ans;
        std::queue<Info> q;
        if (root == nullptr) {
            return ans;
        }
        q.push(Info(root, 0));
        int level = 0;
        while (!q.empty()) {
            std::vector<int> level_ans;
            while (!q.empty() && q.front().level == level) {
                TreeNode* tmp = q.front().node;
                level_ans.push_back(tmp->val);
                q.pop();
                if (tmp->left != nullptr) {
                    q.push(Info(tmp->left, level + 1));
                }
                if (tmp->right != nullptr) {
                    q.push(Info(tmp->right, level + 1));
                }
            }
            ans.push_back(level_ans);
            level++;
        }
        return ans;
    }
};
