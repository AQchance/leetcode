#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    Trie()
    {
        for (size_t i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
        this->is_end = false;
    }

    void insert(string word)
    {
        Trie* p = this;

        for (size_t index = 0; index < word.size(); index++) {
            char ch = word[index];
            Trie* q = p->children[ch - 'a'];
            if (q == nullptr) {
                q = new Trie;
                q->ch = ch;
                q->is_end = false;
                for (size_t i = 0; i < 26; i++) {
                    q->children[i] = nullptr;
                }
                p->children[ch - 'a'] = q;
            }
            if (index == word.size() - 1) {
                q->is_end = true;
            }
            p = q;
        }
    }

    bool search(string word)
    {
        Trie* p = this;
        bool flag = false;
        for (size_t i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (p->children[ch - 'a'] == nullptr) {
                break;
            }
            if (i == word.size() - 1) {
                if (p->children[ch - 'a']->is_end == true) {
                    flag = true;
                }
            }

            p = p->children[ch - 'a'];
        }
        return flag;
    }

    bool startsWith(string prefix)
    {
        Trie* p = this;
        bool flag = true;
        for (size_t i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if (p->children[ch - 'a'] == nullptr) {
                flag = false;
                break;
            }
            p = p->children[ch - 'a'];
        }
        return flag;
    }

private:
    char ch;
    Trie* children[26];
    bool is_end;
};

int main()
{

    Trie* trie = new Trie();
    trie->insert("apple");
    trie->search("apple"); // 返回 True
    trie->search("app"); // 返回 False
    trie->startsWith("app"); // 返回 True
    trie->insert("app");
    trie->search("app"); // 返回 True
}
