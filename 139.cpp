#include <condition_variable>
#include <string>
#include <vector>

using namespace std;

// NOTE: 下面用的是递归，暴力匹配，这个运行超时了，需要考虑其他的思路
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict)
//     {
//         if (s.size() == 0) {
//             return true;
//         }
//         bool flag = false;
//         for (const auto& res : wordDict) {
//             if (s.size() < res.size()) {
//                 continue;
//             } else {
//                 if (s.compare(0, res.size(), res) == 0) {
//                     std::string str = s.substr(res.size(), s.size() - res.size());
//                     flag = flag | wordBreak(str, wordDict);
//                     if (flag == true) {
//                         break;
//                     }
//                 } else {
//                     continue;
//                 }
//             }
//         }
//         return flag;
//     }
// };

struct TrieNode {
    struct TrieNode* child[26];
    bool is_end;
};

TrieNode* create_trie()
{
    TrieNode* root = new TrieNode;
    root->is_end = false;
    for (size_t i = 0; i < 26; i++) {
        root->child[i] = nullptr;
    }
    return root;
}

void insert_word(TrieNode* root, const std::string& word)
{
    TrieNode* p = root;
    for (auto ch : word) {
        int index = ch - 'a';
        if (p->child[index] == nullptr) {
            p->child[index] = create_trie();
            p = p->child[index];
        } else {
            p = p->child[index];
        }
    }
    p->is_end = true;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        TrieNode* root = create_trie();
        for (const auto& word : wordDict) {
            insert_word(root, word);
        }
        for (size_t i = 0; i < s.size(); i++) {
            memory[i] = 0;
        }
        return assist_func(root, s, 0);
    }
    bool assist_func(TrieNode* root, const std::string& s, int pos)
    {
        if (pos == s.size()) {
            return true;
        }
        TrieNode* p = root;
        bool flag = false;
        for (size_t i = pos; i < s.size(); i++) {
            int index = s[i] - 'a';
            if (p->child[index] == nullptr) {
                break;
            }
            p = p->child[index];
            if (p->is_end) {
                if (memory[i + 1] == -1) {
                    flag = false;
                    continue;
                }
                flag = assist_func(root, s, i + 1);
                if (flag == true) {
                    break;
                } else {
                    memory[i + 1] = -1;
                }
            }
        }
        return flag;
    }

private:
    int memory[301];
};
