class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int max_ele=*max_element(arr1.begin(),arr1.end());
        int min_ele=*min_element(arr1.begin(),arr1.end());
        vector<int>map(max_ele+1,0);
        for(auto x : arr1){
            ++map[x];
        }
        arr1={};
        for(auto x : arr2){
            while(map[x]>0){
                arr1.push_back(x);
                --map[x];
            }
        }
        for(int i=0 ; i<map.size() ; ++i){
            while(map[i]>0){
                arr1.push_back(i);
                --map[i];
            }
        }
        return arr1;
    }
};