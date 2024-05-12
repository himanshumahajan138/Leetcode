const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
       
        int n=energy.size();
        
        int maxi=INT_MIN;
        
        int i=n-1;
        
        while(i>=n-k){
            int e=0;
            int j=i;
        
            while(j>=0){
                e+=energy[j];
                maxi=max(maxi,e);
                j-=k;
            }
            --i;
        }
        return maxi;
    }
};