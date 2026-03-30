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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if (left == nullptr) {
                return right;
            }
            if (right == nullptr) {
                return left;
            }
            TreeNode* tmp = left->right;
            left->right = right;
            TreeNode* p = right;
            while (p->left != nullptr) {
                p = p->left;
            }
            p->left = tmp;
            return left;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    Solution sol;
    sol.deleteNode(root, 3);
}
