class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string say=countAndSay(n-1);
        string result="";
        for(int i=0;i<say.length();i++){
         char ch=say[i];
         int count=1;

         while(i<say.length()-1 && say[i]==say[i+1]){
            count++;
            i++;
         }
         //to_string this is used to convert the count in string like countthen to_string(count)="1" become string.
         result+=to_string(count) + string(1,ch);
        }
        return result;
    }
};