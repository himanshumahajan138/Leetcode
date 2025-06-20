class Solution {
public:
    unordered_map<char, pair<int, int>> dir = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}
    };

    int calc(int x1, int y1, int x2, int y2){
        return abs(x1-x2)+abs(y1-y2);
    }

    int maxDistance(string s, int k) {
        int l=0, r=0, u=0, d=0;

        unordered_map<char, int> um;
        int mx=0;
        char ch='&';
        int dist = 0;
        for(auto& val:s){
            if(val=='N'){u++;}
            if(val=='S'){d++;}
            if(val=='W'){l++;}
            if(val=='E'){r++;}

            int calc = abs(u-d) + abs(l-r);
            dist = max(dist, calc);

            int tmp = k;
            int cur = 0;

            // cout<<l<<" "<<r<<endl;
            // cout<<u<<" "<<d<<endl;
            // cout<<endl;

            // left-right
            if(l<r){
                cur += r;
                if(tmp<l){
                    cur += tmp;
                    cur -= (l-tmp);
                    tmp=0;
                }
                else{
                    tmp -= l;
                    cur += l;
                    // l=0;
                }
                // cout<<"cur: "<<cur<<endl;
            }
            else{
                cur += l;
                if(tmp<r){
                    cur += tmp;
                    cur -= (r-tmp);
                    tmp=0;
                }
                else{
                    tmp -= r;
                    cur += r;
                    // r=0;
                }
            }
            
            // down-up
            if(u<d){
                cur += d;
                if(tmp<u){
                    cur += tmp;
                    cur -= (u-tmp);
                    tmp=0;
                }
                else{
                    tmp -= u;
                    cur += u;
                    // l=0;
                }
            }
            else{
                cur += u;
                if(tmp<d){
                    cur += tmp;
                    cur -= (d-tmp);
                    tmp=0;
                }
                else{
                    tmp -= d;
                    cur += d;
                    // r=0;
                }
                // cout<<"cur: "<<cur<<endl;
            }

            dist = max(dist, cur);
        }

        return dist;
    }
};