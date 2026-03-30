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

// NOTE: 这里使用的是递归的方法，不是最优。
// struct Info {
//     int num;
//     int index;
// };
//
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums)
//     {
//         return assist_func(nums, 0, nums.size() - 1);
//     }
//     TreeNode* assist_func(vector<int>& nums, int start, int end)
//     {
//         if (start > end) {
//             return nullptr;
//         }
//         Info info(nums[start], start);
//         for (int i = start; i <= end; i++) {
//             if (nums[i] > info.num) {
//                 info.num = nums[i];
//                 info.index = i;
//             }
//         }
//         TreeNode* node = new TreeNode(info.num);
//         node->left = assist_func(nums, start, info.index - 1);
//         node->right = assist_func(nums, info.index + 1, end);
//         return node;
//     }
// };

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        std::stack<TreeNode*> st;
        for (int i = 0; i < nums.size(); i++) {
            TreeNode* node = new TreeNode(nums[i]);
            if (st.empty()) {
                st.push(node);
            } else {
                while (!st.empty() && st.top()->val < nums[i]) {
                    node->left = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.top()->right = node;
                }
                st.push(node);
            }
        }
        TreeNode* tmp = nullptr;
        while (!st.empty()) {
            tmp = st.top();
            st.pop();
        }
        return tmp;
    }
};
