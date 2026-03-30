#include <queue>

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
    int findBottomLeftValue(TreeNode* root)
    {
        std::queue<Info> q;
        q.push(Info(root, 0));
        int num;
        while (!q.empty()) {
            int level = q.front().level;
            num = q.front().node->val;
            while (!q.empty() && q.front().level == level) {
                TreeNode* node = q.front().node;
                q.pop();
                if (node->left != nullptr) {
                    q.push(Info(node->left, level + 1));
                }
                if (node->right != nullptr) {
                    q.push(Info(node->right, level + 1));
                }
            }
        }
        return num;
    }
};
