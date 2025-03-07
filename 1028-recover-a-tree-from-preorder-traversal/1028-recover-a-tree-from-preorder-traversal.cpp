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
      int n;

    TreeNode* solve(string& s,int &i,int depth){
          if(i>=n)
          return NULL;
 
        int j=i;
          while(j<n && s[j]=='-'){
            j++;
          }
          int dash=j-i;

          if(depth!=dash){
            return NULL;
          }
class Solution {
public:
    int n; // Global variable

    TreeNode* solve(string& s, int &i, int depth) {
        if (i >= n) return NULL;

        // Count number of dashes
        int j = i;
        while (j < n && s[j] == '-') {
            j++;
        }
        int dash = j - i;

        // If depth does not match the number of dashes, return NULL
        if (depth != dash) {
            return NULL;
        }

        i += dash;

        // Extract the number
        int num = 0;
        while (i < n && isdigit(s[i])) {
            num = (num * 10) + (s[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(num);

        // Left and right subtrees should have depth + 1 (not depth + 2 for right child)
        root->left = solve(s, i, depth + 1);
        root->right = solve(s, i, depth + 1);

        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length(); // Use the global 'n'
        int i = 0;
        return solve(traversal, i, 0);
    }
};

          i+=dash;
          int num=0;
          while(i<n && isdigit(s[i])){
            num=(num*10)+(s[i]-'0');
            i++;
          }
          TreeNode* root=new TreeNode(num);
          root->left=solve(s,i,depth+1);
          root->right=solve(s,i,depth+1);

          return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
       n= traversal.length();
        int i=0;
       

        return solve( traversal,i,0);
    }
};