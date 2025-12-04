class Solution {
public:
    static int countCollisions(string& D) {
        int n=D.size();
        if (n==1) return 0;
        int l=D.find_first_not_of('L');
        if (l==-1) l=n-1;
        int r=D.find_last_not_of('R');
        if (r==-1) r=0;
        if (l>=r) return 0;
        return count_if(D.begin()+l, D.begin()+(r+1), 
        [](char c){ return c!='S';});      
    }
};