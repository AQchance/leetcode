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
    vector<int> preorderTraversal(TreeNode* root)
    {
        if (root == nullptr) {
            return std::vector<int>(0);
        }
        std::vector<int> ans;
        std::vector<int> left = preorderTraversal(root->left);
        std::vector<int> right = preorderTraversal(root->right);
        ans.push_back(root->val);
        for (int i = 0; i < left.size(); i++) {
            ans.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            ans.push_back(right[i]);
        }
        return ans;
    }
};
