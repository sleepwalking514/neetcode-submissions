class TrieNode {
public:
    TrieNode* children[26] = { nullptr };
    bool isEnd = false;

    TrieNode() = default;
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (const auto c: word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        bool res = false;
        mySearch(word, 0, root, res);
        return res;
    }

    void mySearch(string& word, int idx, TrieNode* cur, bool& res) {
        if (idx == word.size()) {
            res = cur->isEnd;
            return;
        }

        auto c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (cur->children[i] != nullptr) {
                    mySearch(word, idx + 1, cur->children[i], res);
                }
            }
        } else {
            int i = word[idx] - 'a';
            if (cur->children[i] != nullptr) {
                mySearch(word, idx + 1, cur->children[i], res);
            }
        }
    }
};
