class Solution {
public:
    using int2=pair<int, int>;
    static vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<int2, vector<int2>, greater<int2>> pq;
        const int n=nums.size();
        for(int i=0; i<n; i++){
            pq.emplace(nums[i],i);
        }
        for(int i=0; i<k; i++){
            auto  [x, j]=pq.top();
            pq.pop();
            pq.emplace(multiplier*x, j);
        }
        while(!pq.empty()){
            auto [x,i]=pq.top();
            pq.pop();
            nums[i]=x;
        }
        return nums;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();