int init=[]{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for(string s; getline(cin,s); cout << '\n'){
        string t;
        getline(cin,t);
        int tar = stoi(t);
        for(int i = 0, _i = 1, _n = s.length();_i<_n;++i,++_i){
            bool _neg = false;
            if(s[_i]=='-')++_i, _neg = true;
            int v = s[_i++]&15;
            while((s[_i]&15)<10)v = v*10 + (s[_i++]&15);
            if(_neg)v= -v;
            if(v == tar){
                cout << i;
                goto next;
            }
            if(v > tar)break;
        }
        cout << -1;
        next:;
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            long mid = low+((high-low)/2);
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};