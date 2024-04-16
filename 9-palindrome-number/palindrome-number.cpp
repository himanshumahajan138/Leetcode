class Solution {
public:
    bool isPalindrome(int x) {
        int r=0,temp=x;
        if(x<0){
            return false;
        }
        while(x>0){
            if(r<INT_MIN/10 || r>INT_MAX/10){
                return false;
            }
            r=r*10+x%10;
            x/=10;
        }
        return temp==r ? true : false ;
    }
};