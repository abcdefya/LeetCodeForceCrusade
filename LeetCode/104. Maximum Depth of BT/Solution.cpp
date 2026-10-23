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

// DFS
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root) return 0;
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return 1 + max(left, right);
        }
};


//  BFS
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (!root) return 0;
//         queue <TreeNode*> q;
//         q.push(root);
//         int depth = 0;

//         while (!q.empty()) {
//             int sz = q.size();

//             for (int i = 0; i < sz; i++) {
//                 TreeNode* node = q.front();

//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);

//             }
//             depth++;
//         }

//         return depth;
//     }
// };