#include <climits>
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
    bool isValidBST(TreeNode* root)
    {
        return helper(root, LONG_MAX, LONG_MIN);
    }
    bool helper(TreeNode* root, long upper, long lower)
    {
        if (root->left != nullptr) {
            if (root->left->val >= root->val) {
                return false;
            }
            if (root->left->val >= upper || root->left->val <= lower) {
                return false;
            }
            long new_upper = std::min(static_cast<long>(root->val), upper);
            if (!helper(root->left, new_upper, lower)) {
                return false;
            }
        }
        if (root->right != nullptr) {
            if (root->right->val <= root->val) {
                return false;
            }
            if (root->right->val <= lower || root->right->val >= upper) {
                return false;
            }
            long new_lower = std::max(static_cast<long>(root->val), lower);
            if (!helper(root->right, upper, new_lower)) {
                return false;
            }
        }
        return true;
    }
};
