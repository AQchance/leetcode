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
    int countNodes(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = 1, right_depth = 1;
        TreeNode* left_ptr = root->left;
        TreeNode* right_ptr = root->right;
        while (left_ptr != nullptr) {
            left_ptr = left_ptr->left;
            left_depth++;
        }
        while (right_ptr != nullptr) {
            right_ptr = right_ptr->right;
            right_depth++;
        }
        if (left_depth == right_depth) {
            return std::pow(2, left_depth) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
