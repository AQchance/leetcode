#include <queue>
#include <string>
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

struct Info {

    TreeNode* node;
    std::string prefix;
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> ans;
        if (root == nullptr) {
            return ans;
        }
        std::queue<Info> q;
        q.push(Info(root, ""));
        while (!q.empty()) {
            TreeNode* node = q.front().node;
            std::string prefix = q.front().prefix;
            if (node != root) {
                prefix += "->";
            }
            prefix += std::to_string(node->val);
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                ans.push_back(prefix);
                continue;
            }
            if (node->left != nullptr) {
                q.push(Info(node->left, prefix));
            }
            if (node->right != nullptr) {
                q.push(Info(node->left, prefix));
            }
        }
        return ans;
    }
};
