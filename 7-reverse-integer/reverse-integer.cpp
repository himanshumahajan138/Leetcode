class Solution {
public:
    int reverse(int x) {
        int ans=0,rem=0;
        bool neg=false;
        if(x<0){
            if(x<=INT_MIN){
                return 0 ;
            }
            x = -x;
            neg = true;
        }
        while(x>0){
            if(ans>INT_MAX/10){
                return 0 ;
            }
            rem = x%10;
            ans = ans*10+rem;
            x/=10;
        }
        return neg ? -ans : ans ;
    }
};