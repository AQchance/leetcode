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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end)
    {
        if (pre_start > pre_end) {
            return nullptr;
        }
        int index = in_start;
        for (; index <= in_end && inorder[index] != preorder[pre_start]; index++) {
        }
        int left_size = index - in_start;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        root->left = helper(preorder, inorder, pre_start + 1, pre_start + left_size, in_start, index - 1);
        root->right = helper(preorder, inorder, pre_start + left_size + 1, pre_end, index + 1, in_end);
        return root;
    }
};
