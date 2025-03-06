class Solution {
public:
    TreeNode* solve(int prestart, int postart, int preend, vector<int>& preorder, vector<int>& postorder,
                     unordered_map<int, int>& map) {
        if (prestart > preend) {
            return NULL;
        }
        
        // Create root node
        TreeNode* root = new TreeNode(preorder[prestart]);
        
        // Base case: if it's a single node, return it
        if (prestart == preend) {
            return root;
        }

        // Find the left subtree's root in preorder
        int nextNode = preorder[prestart + 1];

        // Find nextNode's index in postorder using the map
        int j = map[nextNode];
        
        // Number of nodes in left subtree
        int num = j - postart + 1;

        // Recursively construct left and right subtrees
        root->left = solve(prestart + 1, postart, prestart + num, preorder, postorder, map);
        root->right = solve(prestart + num + 1, j + 1, preend, preorder, postorder, map);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        int n = preorder.size();
        
        // Store the index of each value in postorder
        for (int i = 0; i < n; i++) {
            map[postorder[i]] = i;
        }

        return solve(0, 0, n - 1, preorder, postorder, map);
    }
};