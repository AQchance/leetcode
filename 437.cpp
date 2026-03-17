#include <unordered_set>

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
    int pathSum(TreeNode* root, int targetSum)
    {
        target = targetSum;
        ans = 0;
        assist_func(root, targetSum);
        return ans;
    }
    void assist_func(TreeNode* root, long targetSum)
    {
        if (root == nullptr) {
            return;
        }
        if (root->val == targetSum) {
            ans++;
        }
        if (node_used.find(root->left) == node_used.end()) {
            node_used.insert(root->left);
            assist_func(root->left, target);
        }
        assist_func(root->left, targetSum - root->val);
        if (node_used.find(root->right) == node_used.end()) {
            node_used.insert(root->right);
            assist_func(root->right, target);
        }
        assist_func(root->right, targetSum - root->val);
    }

private:
    int target;
    int ans = 0;
    std::unordered_set<TreeNode*> node_used;
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    Solution sol;
    sol.pathSum(root, 3);
}
