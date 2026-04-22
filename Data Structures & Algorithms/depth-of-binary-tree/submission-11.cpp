// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int res = 0;
//         std::queue<TreeNode*> q;
//         if (root != nullptr) q.push(root);

//         while (!q.empty()) {
//             for (int i = 0; i < q.size(); ++i) {
//                 TreeNode* tmp = q.front();
//                 q.pop();
//                 if (tmp->left != nullptr) q.push(tmp->left);
//                 if (tmp->right != nullptr) q.push(tmp->right);
//             }
//             ++res;
//         }

//         return res;
//     }
// };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            level++;
        }
        return level;
    }
};