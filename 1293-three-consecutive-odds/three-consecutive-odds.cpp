const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3)return false;
        for(int i=2 ; i<arr.size();++i){
            if((arr[i]&1)==1 && (arr[i-1]&1)==1 && (arr[i-2]&1)==1)return true;
        }
        return false;
    }
};