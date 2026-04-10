
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
    int kthSmallest(TreeNode* root, int k)
    {
        int cnt = 0;
        return helper(root, k, cnt);
    }
    int helper(TreeNode* root, int k, int& cnt)
    {
        if (root == nullptr) {
            return -1;
        }
        int left_find = helper(root->left, k, cnt);
        if (left_find >= 0) {
            return left_find;
        }
        cnt++;
        if (cnt == k) {
            return root->val;
        }
        int right_find = helper(root->right, k, cnt);
        return right_find;
    }
};
