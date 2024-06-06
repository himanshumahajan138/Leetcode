const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((hand.size() % groupSize) == 0) {
            map<int, int> freq;
            for (auto x : hand)
                ++freq[x];
            for (auto i = freq.begin(); i != freq.end();) {
                if (i->second > 0) {
                    --freq[i->first];
                    int j = i->first + 1;
                    int k = groupSize;
                    while (--k) {
                        if (freq[j] < 1)
                            return false;
                        else {
                            --freq[j];
                            ++j;
                        }
                    }
                }
                if (i->second == 0)
                    ++i;
            }
            return true;
        } else
            return false;
    }
};