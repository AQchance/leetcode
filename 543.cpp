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
private:
    int ans;

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        ans = 0;
        depth(root);
        return ans;
    }
    int depth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        ans = std::max(ans, left_depth + right_depth);
        return std::max(left_depth, right_depth) + 1;
    }
};
