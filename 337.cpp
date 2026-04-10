#include <unordered_map>
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

// NOTE: 这个方法因为设置了father_used这个参数，本质上就变成了一个O(2^n)复杂度的暴力递归
// class Solution {
// public:
//     int rob(TreeNode* root)
//     {
//         return helper(root, false);
//     }
//     int helper(TreeNode* root, bool father_used)
//     {
//         if (root == nullptr) {
//             return 0;
//         }
//         if (father_used) {
//             return helper(root->left, false) + helper(root->right, false);
//         } else {
//             int use_cur = helper(root->left, true) + helper(root->right, true) + root->val;
//             int not_use_cur = helper(root->left, false) + helper(root->right, false);
//             return std::max(use_cur, not_use_cur);
//         }
//     }
// };

// NOTE: 第二版，这个方法因为不需要状态参数，因此时间复杂度降低到了O(N)，但是额外空间是整个的哈希表，空间上面还有优化空间。
// class Solution {
// public:
//     int rob(TreeNode* root)
//     {
//         std::unordered_map<TreeNode*, int> dp;
//         dp[nullptr] = 0;
//         post_order(root, dp);
//         return dp[root];
//     }
//     void post_order(TreeNode* root, std::unordered_map<TreeNode*, int>& dp)
//     {
//         if (root == nullptr) {
//             return;
//         }
//         post_order(root->left, dp);
//         post_order(root->right, dp);
//         int not_use_cur = dp[root->left] + dp[root->right];
//         int use_cur = root->val;
//         if (root->left != nullptr) {
//             use_cur += dp[root->left->left] + dp[root->left->right];
//         }
//         if (root->right != nullptr) {
//             use_cur += dp[root->right->left] + dp[root->right->right];
//         }
//         dp[root] = std::max(use_cur, not_use_cur);
//     }
// };
//
//
struct Info {
    int use_cur;
    int not_use_cur;
};
class Solution {
public:
    int rob(TreeNode* root)
    {
        Info root_status = post_order(root);
        return std::max(root_status.not_use_cur, root_status.use_cur);
    }
    Info post_order(TreeNode* root)
    {
        if (root == nullptr) {
            return { 0, 0 };
        }
        Info left_status = post_order(root->left);
        Info right_status = post_order(root->right);
        int use_cur = left_status.not_use_cur + right_status.not_use_cur + root->val;
        int not_use_cur = std::max(left_status.use_cur, left_status.not_use_cur) + std::max(right_status.use_cur, right_status.not_use_cur);
        return { use_cur, not_use_cur };
    }
};
