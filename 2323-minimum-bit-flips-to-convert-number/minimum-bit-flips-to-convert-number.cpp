class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = start^goal;
        int count=0;
        while(result!=0){
            result=result & (result-1);
            count++;
        }
        return count;
    }
};