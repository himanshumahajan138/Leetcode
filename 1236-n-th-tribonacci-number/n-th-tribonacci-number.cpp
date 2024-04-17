class Solution {
public:
    int tribonacci(int n) {
        int mem[n+3];
        mem[0]=0;
        mem[1]=1;
        mem[2]=1;
        for(int i=3;i<=n;i++){
            mem[i]=mem[i-3]+mem[i-2]+mem[i-1];
        }
        return mem[n];
    }
};