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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL )
        return {};

        queue<TreeNode*>que;
       
        que.push(root);
        
        vector<vector<int>>v;

        while(!que.empty()){
            int size=que.size();
            vector<int>v1;

            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();

            v1.push_back(node->val);

            if(node->left)
            que.push(node->left);

            if(node->right)
            que.push(node->right);

            
            }
            v.insert(v.begin(),v1);
        }
        return v;
    }
};