class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();

        int MaxScore=0;

        sort(tokens.begin(),tokens.end());

       int i=0; int j=n-1;
        
        int score=0;
        
       while(i<=j){
        if(power >= tokens[i]){
            power -= tokens[i]; // losing token 
            score += 1;
            i++;
            MaxScore =max(MaxScore,score);

        }
        else if(score >= 1 ){
            power += tokens[j];
            score -=1;
            j--;
        }
        else{
            return MaxScore;
        }
       }
        return MaxScore;
    }
};