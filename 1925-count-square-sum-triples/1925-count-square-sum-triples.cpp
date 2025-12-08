class Solution {
public:
    int countTriples(int n) {
        int count=0;

        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                int S=(a*a)+(b*b);
                int X=sqrt(S);

                if(X*X == S && X<=n){
                    count+=2;
                }
            }
        }
        return count;
    }
};