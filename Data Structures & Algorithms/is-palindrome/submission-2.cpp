class Solution {
public:
    bool isPalindrome(string s) {
        string trans;

        for (auto& c: s) {
            if (isalnum(c)) {
                if (isupper(c)) c = tolower(c);
                trans.push_back(c);
            }
        }

        int len = trans.size();
        for (int i = 0; i < len / 2; i++) {
            if (trans[i] != trans[len - 1 - i]) return false;
        }
        return true;
    }
};
