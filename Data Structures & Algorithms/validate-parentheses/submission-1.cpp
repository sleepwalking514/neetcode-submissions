class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> umap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        std::vector<char> vec;

        for (const auto& c: s) {
            if (c == '(' || c == '[' || c == '{') {
                vec.push_back(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (vec.empty()) return false;
                if (umap[c] == vec.back()) {
                    vec.pop_back();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return vec.empty();
    }
};
