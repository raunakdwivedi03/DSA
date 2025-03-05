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
    if (root == NULL) return {};  // Base case

    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root); // Push root into queue

    while (!q.empty()) {
        int size = q.size();
        vector<int> level; // Stores nodes of the current level

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);  // Push left child
            if (node->right) q.push(node->right); // Push right child
        }

        result.push_back(level); // Add level to result
    }

    return result;
}


};