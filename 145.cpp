#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> ans;
        std::stack<TreeNode*> st;
        if (root == nullptr) {
            return ans;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            ans.push_back(tmp->val);
            st.pop();
            if (tmp->left != nullptr) {
                st.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                st.push(tmp->right);
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
