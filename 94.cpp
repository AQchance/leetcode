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
    vector<int> inorderTraversal(TreeNode* root)
    {
        TreeNode* p = root;
        std::stack<TreeNode*> s;
        std::vector<int> ans;
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            ans.push_back(tmp->val);
            s.pop();
            TreeNode* q = tmp->right;
            while (q != nullptr) {
                s.push(q);
                q = q->left;
            }
        }
        return ans;
    }
};
