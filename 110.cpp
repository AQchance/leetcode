#include <cmath>

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

class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (std::abs(left_depth - right_depth) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if (left_depth > right_depth) {
            return 1 + left_depth;
        } else {
            return 1 + right_depth;
        }
    }
};
