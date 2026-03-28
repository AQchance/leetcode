#include <stack>
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
        // 这里是使用递归的方式来实现。
        //     if (root == nullptr) {
        //         return std::vector<int>(0);
        //     }
        //     std::vector<int> ans;
        //     std::vector<int> left = preorderTraversal(root->left);
        //     std::vector<int> right = preorderTraversal(root->right);
        //     ans.push_back(root->val);
        //     for (int i = 0; i < left.size(); i++) {
        //         ans.push_back(left[i]);
        //     }
        //     for (int i = 0; i < right.size(); i++) {
        //         ans.push_back(right[i]);
        //     }
        //     return ans;

        // 下面使用迭代的方式来实现
        std::stack<TreeNode*> s;
        std::vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            ans.push_back(tmp->val);
            s.pop();
            if (tmp->right != nullptr) {
                s.push(tmp->right);
            }
            if (tmp->left != nullptr) {
                s.push(tmp->left);
            }
        }
        return ans;
    }
};
