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
    void flatten(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                cur = cur->right;
                continue;
            }
            TreeNode* right = cur->right;
            TreeNode* left = cur->left;
            TreeNode* tmp = left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            tmp->right = right;
            cur->right = left;
            cur->left = nullptr;
            cur = left;
        }
    }
};
