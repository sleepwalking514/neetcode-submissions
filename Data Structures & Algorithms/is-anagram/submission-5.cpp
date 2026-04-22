class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> sArr(26);
        vector<int> tArr(26);

        for (int i = 0; i < s.size(); i++) {
            sArr[s[i] - 'a']++;
            tArr[t[i] - 'a']++;
        }

        return sArr == tArr;
    }
};
