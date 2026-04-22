/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int m = 0;
        dfs(root, m, 1);
        return m;
    }

    void dfs(TreeNode* tn, int& m, int curr) {
        if (tn) {
            if (tn->left) dfs(tn->left, m, curr + 1);
            if (tn->right) dfs(tn->right, m, curr + 1);
            m = max(m, curr);
        }
    }
};
