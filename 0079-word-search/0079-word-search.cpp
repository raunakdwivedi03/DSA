class Solution {
public:
    int n,m;
    bool find(vector<vector<char>>& board, int i, int j, int idx, string &word){
        if(idx == word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] == '$'){
            return false;
        }
        if(board[i][j] != word[idx]){
            return false;
        }
        //marking visisted
        char temp= board[i][j];
        board[i][j] = '$';
 
  //Down
   if (find(board, i + 1, j, idx + 1, word)) 
    return true;

// Up
   if (find(board, i - 1, j, idx + 1, word)) 
    return true;

// Right
  if (find(board, i, j + 1, idx + 1, word)) 
    return true;

// Left
   if (find(board, i, j - 1, idx + 1, word)) 
    return true;

    
board[i][j] = temp;

 return false;

    };

    bool exist(vector<vector<char>>& board, string word) {
         n=board.size();
         m=board[0].size();

      int i=0;
      while(i<n){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0] && find(board,i,j,0,word)){
                return true;
            }
        }
        i++;
      }   
      return false;
    }
};