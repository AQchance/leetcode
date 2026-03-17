#include <unordered_map>

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
    int maxPathSum(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        ans = -9999;
        side_max(root);
        return ans;
    }
    // 下面这个函数只是用来计算节点的一边（不包括节点）的最长路径。
    int side_max(TreeNode* root)
    {
        if (root == nullptr) {
            return -9999;
        }
        int left = side_max(root->left);
        int right = side_max(root->right);
        ans = std::max(ans, left);
        ans = std::max(ans, right);
        ans = std::max(ans, root->val);
        ans = std::max(ans, root->val + left);
        ans = std::max(ans, root->val + right);
        ans = std::max(ans, root->val + left + right);
        if (right < 0 && left < 0) {
            return root->val;
        } else {
            if (right > left) {
                return root->val + right;
            } else {
                return root->val + left;
            }
        }
    }

private:
    int ans;
};
