#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class WordDictionary {
public:
   class Node {
    public:
        Node* pChild[26];
        bool exists; // decide if the node a word
        Node():exists(false) {
            memset(pChild, 0, sizeof(Node*) * 26);
        }
    } ;

    WordDictionary() {
        // build trie tree
        root = new Node();
        root->exists = true;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int size = word.size();
        Node* cur = root;
        for (char ch : word) {
            Node*& n = cur->pChild[ch - 'a'];
            cur = n ? n : (n=new Node());
        }

        cur->exists = true;
    }

    bool dfs(Node* cur, int ind, const string& word) {
        if (ind == word.size()) {
            return cur->exists;
        }

        if (word[ind] == '.') {
            for (auto& n: cur->pChild) {
                if (n && dfs(n, ind+1, word)) {
                    return true;
                }
            }
        } else {
            Node*& n = cur->pChild[word[ind] - 'a'];
            return n ? dfs(n, ind+1, word) : false;
        }
        return false;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(root, 0, word);
    }
private:
  Node* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
  WordDictionary s;
  s.addWord("ab");
  cout << s.search("a.") << endl;
}
