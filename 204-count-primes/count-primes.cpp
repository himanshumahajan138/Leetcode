class Solution {
public:
    void seive_of_eratosthenes(vector<int>&seive, int n){
        for(int i=2 ; i*i<n;++i){
            if(seive[i]==1){
                for(int j=i*i ; j<n ; j+=i){
                    seive[j]=0;
                }
            }
        }
    }
    int countPrimes(int n) {
        vector<int>seive(n,1);
        seive_of_eratosthenes(seive,n);
        int cnt=0;
        for(int ele=2;ele<seive.size();++ele){
            if(seive[ele]==1)++cnt;
        }
        return cnt;
    }
};