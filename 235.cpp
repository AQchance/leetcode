#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == p || root == q || root == nullptr) {
            return root;
        }
        int large = std::max(p->val, q->val);
        int less = std::min(p->val, q->val);
        if (less < root->val && large > root->val) {
            return root;
        }
        if (less < root->val && large < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (less > root->val && large > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return nullptr;
    }
};
