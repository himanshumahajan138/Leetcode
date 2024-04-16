class Solution {
public:
    double myPow(double x, int n) {
        long nn=n;
        if(nn==0)return 1;
        if(nn<0){
            nn=-1*nn;
            x=1/x;
        }
        if(nn%2==0){
            return myPow(x*x,(int)(nn/2));
        }
        else{
            return x*myPow(x,(int)(nn-1));
        }
    }
};