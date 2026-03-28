#include <vector>

#include <queue>

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
    vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        std::queue<Info> q;
        q.push(Info(root, 0));
        int level = 0;
        while (!q.empty()) {
            int num = q.front().node->val;
            while (!q.empty() && q.front().level == level) {
                TreeNode* tmp = q.front().node;
                q.pop();
                num = tmp->val;
                if (tmp->left != nullptr) {
                    q.push(Info(tmp->left, level + 1));
                }
                if (tmp->right != nullptr) {
                    q.push(Info(tmp->right, level + 1));
                }
            }
            ans.push_back(num);
            level++;
        }
        return ans;
    }
};
