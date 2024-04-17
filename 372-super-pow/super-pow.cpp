const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    long long solve(int num,int power,int mod){
        if(power==0){
            return 1;
        }
        if(power==1) return num;
        long long res=1;
        res=solve(num,power/2,mod)%mod;
        res=(res*res)%mod;
        if(power&1) {
            res=(res*num)%mod;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int mod=1337;
        int result=1;
        int n=b.size();
        long long ans=1;
        for(int i=0;i<n;i++){
            ans=((solve(ans,10,mod))%mod*(solve(a,b[i],mod))%mod)%mod;
        }
        return ans;
    }
};