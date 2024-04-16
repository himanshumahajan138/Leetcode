class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(1,1);
        long long int prev=1;
        for(int i=1;i<=rowIndex;i++){
            long long int next=prev*(rowIndex-i+1)/i;
            ans.push_back(next);
            prev=next;
        }
        return ans;
    }
};