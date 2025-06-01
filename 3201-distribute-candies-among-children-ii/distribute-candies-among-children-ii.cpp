#define ll long long
class Solution {
public:
    ll distributeCandies(int choco, int l) {
        ll ans = 0;

        for (ll x = max(0ll, (ll)choco - 2 * (ll)l); x <= min((ll)choco, (ll)l); x++) {
            ll y_st = max(0ll, (ll)choco - (ll)l - x);
            ll y_en = min((ll)choco - x, (ll)l);

            if (y_st <= y_en) {
                ll range = (y_en - y_st + 1);
                ans += range;
            }
        }

        return ans;
    }
};