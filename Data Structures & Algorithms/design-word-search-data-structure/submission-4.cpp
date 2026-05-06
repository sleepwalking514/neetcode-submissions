class TrieNode {
public:
    TrieNode* children[26] = { nullptr };
    bool isEnd = false;

    TrieNode() = default;
};

class WordDictionary {
    TrieNode* root = new TrieNode();

public:
    WordDictionary() = default;
    
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
        return mySearch(word, 0, root);
    }

    bool mySearch(string& word, int idx, TrieNode* cur) {
        if (idx == word.size()) {
            return cur->isEnd;
        }

        auto c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (cur->children[i] != nullptr &&
                    mySearch(word, idx + 1, cur->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int i = word[idx] - 'a';
            if (cur->children[i] != nullptr) {
                return mySearch(word, idx + 1, cur->children[i]);
            }
            return false;
        }
    }
};
