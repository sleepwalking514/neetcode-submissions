class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        // Use the sorted string as key for grouping
        for (const auto& c: strs) {
            string s = c;
            sort(s.begin(), s.end());
            umap[s].push_back(c);
        }

        vector<vector<string>> ans;
        for (const auto& it: umap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
