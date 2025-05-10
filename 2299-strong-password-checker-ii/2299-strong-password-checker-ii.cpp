class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n=password.size();

        if(n<8)
        return false;

        string Specialchar="!@#$%^&*()-+";

        bool UpperCase=false, LowerCase=false, hasSpecialChar=false, number=false;
          
           for(int i=0;i<=n;i++){
             char c=password[i];


             if(i>0 && password[i]==password[i-1])
             return false;

             if(islower(c))
             LowerCase=true;
             
             else if(isupper(c))
               UpperCase=true;

             
            else if(isdigit(c))
               number=true;

          else {
            for(int j=0;j<Specialchar.length();j++){
              if(c==Specialchar[i])
              hasSpecialChar=true;
            }
           }
      }

      return LowerCase && UpperCase && number && hasSpecialChar;
    }
};