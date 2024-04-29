const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int countPrimes(int n) {
        vector<int>prime(n+1,1);
        for(int i=2;i*i<=n;++i){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        int count=0;
        for(int i = 2 ; i<n ;++i){
            if(prime[i]==1)count++;
        }
        return count;
    }
};