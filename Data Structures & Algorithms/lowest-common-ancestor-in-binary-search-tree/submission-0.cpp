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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1 = root->val, v2 = p->val, v3 = q->val;

        if (v1 > v2 && v1 > v3) return lowestCommonAncestor(root->left, p, q);

        if (v1 < v2 && v1 < v3) return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};
