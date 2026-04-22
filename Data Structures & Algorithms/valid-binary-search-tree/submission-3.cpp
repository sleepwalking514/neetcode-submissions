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
    bool isValidBST(TreeNode* root) {
        return isValidWithinRange(root, -1001, 1001);
    }

    bool isValidWithinRange(TreeNode* root, int leftBound, int rightBound) {
        if (root == nullptr) return true;

        if (root->val > leftBound && root->val < rightBound) {
            return isValidWithinRange(root->left, leftBound, root->val) && \
                   isValidWithinRange(root->right, root->val, rightBound);
        }

        return false;
    }
};
