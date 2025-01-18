const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};
const int N = 10000;
class Solution {
public:
    static inline bool isOutside(int i, int j, int r, int c) {
        return i < 0 || i >= r || j < 0 || j >= c;
    }
    static inline unsigned pack(unsigned d, unsigned i, unsigned j) {
        return (d << 16) + (i << 8) + j;
    }
    static inline array<int, 3> unpack(unsigned info) {
        array<int, 3> ans;
        ans[0] = info >> 16, ans[1] = (info >> 8) & 255, ans[2] = info & 255;
        return ans;
    }
    static unsigned int idx(int i, int j, int c) { return i * c + j; }

    static int minCost(vector<vector<int>>& grid) {
        const int r = grid.size(), c = grid[0].size();
        unsigned q[N];
        int front=0, back=0;
        unsigned* dist = (unsigned*)alloca(r * c * sizeof(unsigned));
        bitset<N> viz = 0;
        fill(dist, dist + r * c, UINT_MAX);
        q[back++]=pack(0, 0, 0);
        dist[0] = 0;
    //    viz[0] = 1;
        while (front!=back) {
            auto info = q[front++];
            if (front>=N) front-=N;

            auto [d, i, j] = unpack(info);
        //    viz[idx(i, j, c)] = 1;
            if (i == r - 1 && j == c - 1)
                return d;
            int x = grid[i][j];
            for (int a = 0; a < 4; a++) {
                int s = i + di[a], t = j + dj[a];
                if (isOutside(s, t, r, c) /*|| viz[idx(s, t, c)]*/)
                    continue;
                int new_d = d + 1 - (a + 1 == x);
                int b = idx(s, t, c);
                if (new_d < dist[b]) {
                    dist[b] = new_d;
                    if (a+1==x){
                        if (front==0) front=N;
                        q[--front]=pack(new_d, s, t);
                    }
                    else{
                        q[back++]=pack(new_d, s, t);
                        if (back>=N) back-=N;
                    }
                }
            }
        }
        return INT_MAX;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();