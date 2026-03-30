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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return assist_func(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* assist_func(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int po_start, int po_end)
    {
        if (in_start > in_end || po_start > po_end) {
            return nullptr;
        }
        int size = in_end - in_start + 1;
        TreeNode* node = new TreeNode(postorder[po_end]);
        int index = in_start;
        for (; index <= in_end && inorder[index] != postorder[po_end]; index++) { }
        node->left = assist_func(inorder, in_start, index - 1, postorder, po_start, po_start + index - in_start - 1);
        node->right = assist_func(inorder, index + 1, in_end, postorder, po_start + index - in_start, po_end - 1);
        return node;
    }
};
