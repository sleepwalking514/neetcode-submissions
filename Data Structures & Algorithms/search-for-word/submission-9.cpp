class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                bool ans = false;
                if (board[i][j] != word[0]) continue;
                set<pair<int, int>> us = { {i, j} };
                search(board, word, i, j, 1, ans, us);
                if (ans) return true;
            }
        }
        return false;
    }

    void search(
        vector<vector<char>>& board, string word,
        int x, int y, int idx, bool& ans, 
        set<pair<int, int>>& us
    ) {
        if (idx == word.size()) {
            ans = true;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];

            if (newX < 0 || newX >= board.size() ||
                newY < 0 || newY >= board[0].size())
            {
                continue;
            }

            if (board[newX][newY] == word[idx] && 
                !us.count({newX, newY}))
            {
                us.insert({newX, newY});
                search(board, word, newX, newY, idx + 1, ans, us);
                us.erase({newX, newY});
            }
        }
    }
};
