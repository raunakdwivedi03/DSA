class Solution {
public:
    // total ASCII character is 256.
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();

     if (n!=m) return false;

      unordered_map<char,char>mapS;
      unordered_map<char,char>mapT;

      for(int i=0;i<n;i++){
        char ch_S = s[i];
        char ch_T = t[i];

        if(mapS.find(ch_S) != mapS.end() && mapS[ch_S] != ch_T || 
           mapT.find(ch_T) != mapT.end() && mapT[ch_T] != ch_S){
            return false;
           }
           mapS[ch_S] = ch_T;
           mapT[ch_T] = ch_S;
      }
      return true;
    }
};