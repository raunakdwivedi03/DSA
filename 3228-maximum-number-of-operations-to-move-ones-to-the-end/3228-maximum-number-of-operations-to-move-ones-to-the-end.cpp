class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int i=0;
        int result=0;
        int count1Seen =0;

        while(i<n){
            if(s[i] == '0'){
                result +=count1Seen;
                while(i<n && s[i] == '0'){
                    i++;
                }
            }
                else{
                    count1Seen++;
                    i++;
                }
            
        }
            return result;
        
    }
};