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
    int maxDepth(TreeNode* root)
    {
        int level = 0;
        if (root == nullptr) {
            return level;
        }
        std::queue<Info> q;
        q.push(Info(root, 1));
        while (!q.empty()) {
            TreeNode* node = q.front().node;
            level = q.front().level;
            q.pop();
            if (node->left != nullptr) {
                q.push(Info(node->left, level + 1));
            }
            if (node->right != nullptr) {
                q.push(Info(node->right, level + 1));
            }
        }
        return level;
    }
};
