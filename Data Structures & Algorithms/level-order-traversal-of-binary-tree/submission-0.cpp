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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        std::vector<std::vector<int>> res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            std::vector<int> level;
            for (int i = 0; i < s; ++i) {
                TreeNode* tmp = q.front();
                level.push_back(tmp->val);
                q.pop();

                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            res.push_back(level);
        }

        return res;
    }
};
