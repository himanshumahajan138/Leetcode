class Solution {
public:
    int kthFactor(int n, int k) {
        //finding factor
        int count = 0, ans = -1;
        
        //rest elements
        for(int i = 1; i <= n/2 ; i++){
            if(n % i == 0){
                count++;
                if(k == count){
                    return (i);
                }
            }
        }
        if(count >= k){
            return -1;
        }
        if(count + 1 == k){
            ans = n;
        }
        return ans;
    }
};