class Solution {
public:    
    int count_pairs(vector<int>&arr,int low,int mid,int high){
        int cnt=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && arr[i]>2LL*arr[right])right++;
            cnt+=(right-(mid+1));
        }
        return cnt;
    }

    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int left = low;
        int right = mid+1;
        while(left<=mid&&right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }

    int merge_sort(vector<int>&arr,int low ,int high){
        int mid=(low+high)/2;
        int cnt=0;
        if(low>=high)return cnt;
        cnt+=merge_sort(arr,low,mid);
        cnt+=merge_sort(arr,mid+1,high);
        cnt+=count_pairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};