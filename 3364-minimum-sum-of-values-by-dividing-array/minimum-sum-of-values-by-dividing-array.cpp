const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const ll INF = LONG_LONG_MAX - 1;

class Solution {
public:
    ll highestPowerof2LessThanOrEq(ll x) {
    // check for the set bits
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return x ^ (x >> 1);
}
    
    template <class T> class Segtree {

private:

    const T DEFAULT = (1ll << 60);  // Will overflow if T is an int


    vector<T> segtree;

    int len;


public:

    Segtree(int len) : len(len), segtree(len * 2, DEFAULT) {}


    /** Sets the value at ind to val. */

    void set(int ind, T val) {

        ind += len;

        segtree[ind] = val;

        for (; ind > 1; ind /= 2) {

            segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);

        }

    }


     /** @return the max element in the range [start, end] */

    T rmin(int start, int end) {
        end++;
        T sum = DEFAULT;

        for (start += len, end += len; start < end; start /= 2, end /= 2) {

            if (start % 2 == 1) { sum = std::min(sum, segtree[start++]); }

            if (end % 2 == 1) { sum = std::min(sum, segtree[--end]); }

        }

        return sum;

    }

};
    
    ll dp[(int) 1e5 + 3][15];
    int sp[(int) 3e5][30];
int query(int l, int r){
    if (r == l)
        return sp[r][0];
    int d = (int) log2(highestPowerof2LessThanOrEq(r-l));
    return sp[l][d] & sp[r-(1<<d)+1][d];
}
    
    int minimumValueSum(vector<int>& a, vector<int>& b) {

    int n = a.size();
    int m = b.size();

    for (int i = 0; i < n; ++i)
        sp[i][0] = a[i];


    int LOGN = ceil(log2(n));
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 0; i < n - (1 << j) + 1; ++i) {
            sp[i][j] = sp[i][j-1] & sp[i+(1<<(j-1))][j-1];
        }
    }

    vector<Segtree<ll>> P(m + 2,Segtree<ll>(n+3));
    for (int w = 0; w <= m+2; ++w)
        for (int i = 0; i <= n+2; ++i)
            dp[i][w] = INF/3;
    dp[n][m] = 0;

    P[m].set(n,a[n-1]);


    for (int w = m-1; w >= 0; --w){
        for (int i = n-1; i >= 0; --i){
            int L = n;
            int l = i;
            int r = n-1;
            while ((r-l) > 1){
                int mi = (r+l) >> 1;
                if (query(i,mi) > b[w])
                    l = mi+1;
                else
                    r = mi;
            }
            if (query(i,l) == b[w])
                L = l;
            else if (query(i,r) == b[w])
                L = r;

            int R = i;
            l = i;
            r = n-1;
            while ((r-l) > 1){
                int mi = (r+l) >> 1;
                if (query(i,mi) < b[w])
                    r = mi-1;
                else
                    l = mi;
            }
            if (query(i,r) == b[w])
                R = r;
            else if (query(i,l) == b[w])
                R = l;

            /*for (int j = L; j <= R; ++j){
                dp[i][w] = min(dp[i][w], a[j] + dp[j+1][w+1]);
            }*/
            if (L <= R)
                dp[i][w] = P[w+1].rmin(L+1,R+1);
            if (i > 0)
                P[w].set(i,dp[i][w] + a[i-1]);
        }
    }

    return dp[0][0] > INF/10 ? -1 : dp[0][0];


    }
};