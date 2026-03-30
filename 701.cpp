
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
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr) {
            return node;
        }
        if (val < root->val) {
            if (root->left != nullptr) {
                insertIntoBST(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else if (val > root->val) {
            if (root->right != nullptr) {
                insertIntoBST(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
        return root;
    }
};
