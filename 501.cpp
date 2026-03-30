#include <climits>
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
    TreeNode* pre = nullptr;
    std::vector<int> ans;
    int max_frequency = INT_MIN;
    int current_frequency = 0;

public:
    vector<int> findMode(TreeNode* root)
    {
        helper(root);
        return ans;
    }
    void helper(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        helper(root->left);
        if (pre == nullptr) {
            current_frequency++;
        } else if (pre->val == root->val) {
            current_frequency++;
        } else {
            current_frequency = 1;
        }

        if (current_frequency == max_frequency) {
            ans.push_back(root->val);
        } else if (current_frequency > max_frequency) {
            ans.clear();
            ans.push_back(root->val);
            max_frequency = current_frequency;
        }
        pre = root;
        helper(root->right);
    }
};
