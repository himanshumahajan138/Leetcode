class Solution {
public:
    long long mod= 1e9+7;
    long long pow(long long a, long long b){
        long long ans=1;
        while(b>0){
            if (b%2){
                ans=(ans*a)%mod;
                b--;
            }else{
                a=(a*a)%mod;
                b/=2;
            }
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long e=5;
        long long o=4;
        long long even=n/2+n%2;
        long long odd=n/2;
        return (pow(e,even)*pow(o,odd))%mod;
    }
};