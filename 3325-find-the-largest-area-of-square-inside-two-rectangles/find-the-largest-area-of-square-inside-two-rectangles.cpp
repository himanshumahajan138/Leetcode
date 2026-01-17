using int4=tuple<int, int, int, int>;
int4 Rect[1000];
class Solution {
public:  
    static long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        const int n=bottomLeft.size();
        long long maxSide=0;
        for(int i=0; i<n; i++)
            Rect[i]={bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]};
        sort(Rect, Rect+n);
        for(int r=1; r<n; r++){
            auto& [a, b, c, d]=Rect[r];
            for(int l=0; l<r; l++){
                auto& [aj, bj, cj, dj]=Rect[l];
                const long long width=min(cj, c)-a;
                const long long height=min(dj, d)-max(bj, b);
                const long long s=min(width, height);
                if(s>maxSide) maxSide=s;
            }
        }
        return maxSide*maxSide;
    }
};