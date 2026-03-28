#include <vector>

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
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left_sum = 0;
        int right_sum = 0;
        if (root->left == nullptr) {
            left_sum = 0;
        } else if (is_leaf(root->left)) {
            left_sum += root->left->val;
        } else {
            left_sum = sumOfLeftLeaves(root->left);
        }
        right_sum = sumOfLeftLeaves(root->right);
        return left_sum + right_sum;
    }
    bool is_leaf(TreeNode* root)
    {
        return root->left == nullptr && root->right == nullptr;
    }
};
