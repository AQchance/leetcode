#include <cmath>
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
    int getMinimumDifference(TreeNode* root)
    {
        int ans = 100000;
        if (root->left != nullptr) {
            TreeNode* tmp = root->left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            ans = std::min(ans, std::abs(root->val - tmp->val));
            ans = std::min(ans, getMinimumDifference(root->left));
        }
        if (root->right != nullptr) {
            TreeNode* tmp = root->right;
            while (tmp->left != nullptr) {
                tmp = tmp->left;
            }
            ans = std::min(ans, std::abs(root->val - tmp->val));

            ans = std::min(ans, getMinimumDifference(root->right));
        }
        return ans;
    }
};
