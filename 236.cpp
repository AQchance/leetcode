#include <bitset>
#include <iostream>

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

// NOTE: 这个做法是比较简单的，但是也比较耗时的
// 比较耗时的原因是因为has_node函数在使用的时候是每次只能单独查看一个节点是否在子树中
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         if (root == nullptr) {
//             return nullptr;
//         }
//         if (has_node(root->left, p) && has_node(root->left, q)) {
//             return lowestCommonAncestor(root->left, p, q);
//         } else if (has_node(root->right, p) && has_node(root->right, q)) {
//             return lowestCommonAncestor(root->right, p, q);
//         } else {
//             return root;
//         }
//     }
//
//     bool has_node(TreeNode* root, TreeNode* p)
//     {
//         if (root == nullptr) {
//             return false;
//         }
//         if (root == p) {
//             return true;
//         }
//         return has_node(root->left, p) || has_node(root->right, p);
//     }
// };

// NOTE: 自己的优化版本，这一次可以一次性检索两个节点是否在一个子树中
// 性能比前面的好一点
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         if (root == nullptr) {
//             return nullptr;
//         }
//         has_node(root->left, p, q, flags);
//         if (flags.all()) {
//             flags.reset();
//             return lowestCommonAncestor(root->left, p, q);
//         }
//         flags.reset();
//         has_node(root->right, p, q, flags);
//         if (flags.all()) {
//             flags.reset();
//             return lowestCommonAncestor(root->right, p, q);
//         }
//         return root;
//     }
//
//     // 如果有p置位flag[0] 如果有q置位flag[1]
//     void has_node(TreeNode* root, TreeNode* p, TreeNode* q, std::bitset<2>& flags)
//     {
//         if (root == nullptr) {
//             return;
//         }
//         if (root == p) {
//             flags.set(0);
//         }
//         if (root == q) {
//             flags.set(1);
//         }
//         has_node(root->left, p, q, flags);
//         has_node(root->right, p, q, flags);
//     }
//
// private:
//     std::bitset<2> flags;
// };

// NOTE: 这个方法是比较快的
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }
};
