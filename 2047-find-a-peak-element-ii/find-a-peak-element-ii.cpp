const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int find_max_ele_index(vector<vector<int>>& mat,int col){
        int max_ele=-1,index=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>max_ele){
                max_ele=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int max_ele_index=find_max_ele_index(mat,mid);
            int left = mid-1>=0 ? mat[max_ele_index][mid-1] : -1;
            int right = mid+1<mat[0].size() ? mat[max_ele_index][mid+1] : -1;
            if(mat[max_ele_index][mid]>left && mat[max_ele_index][mid]>right){
                return {max_ele_index,mid};
            }
            else if(mat[max_ele_index][mid]<left)high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};