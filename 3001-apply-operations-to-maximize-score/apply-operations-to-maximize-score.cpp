const int N=sqrt(100000);
vector<bool> isPrime(N+1, 1);
vector<int> prime;
int st[100000];

using int2 = pair<int, int>;

// radix sort for int2
const int Bz=256, Bmask=255, bz=8;
vector<int2> bucket[Bz];
void radix_sort(vector<int2>& nums, int N) {
    int xmin=INT_MAX, xmax=INT_MIN;
    for(int i=0; i<N; i++){
        auto& [x, _]=nums[i];
        xmin=min(xmin, x);
        xmax=max(xmax, x);
    }
    unsigned xrange = xmax- xmin + 1;
    int round = max(1, int(32-countl_zero(xrange) + bz-1) / bz);

    // 0th round
    for (auto& [x, idx] : nums) {
        x -= xmin; // Adjust x by xmin
        bucket[x & Bmask].emplace_back(x += (round == 1) ? xmin : 0, idx);
    }

    int i = 0;
    for (auto& B : bucket) {
        for (auto& v : B)
            nums[i++] = v;
        B.clear(); // Clear bucket after usage
    }
    //    print(nums);

    // Rounds from 1st to (round-2)th round
    for (int rd = 1; rd < round - 1; rd++) {
        int shift = rd * bz; // Bit shifting to extract the next set of bz bits
        for (auto& [x, idx] : nums)
            bucket[(x >> shift) & Bmask].emplace_back(x, idx);

        i = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[i++] = v;
            B.clear(); // Clear bucket after usage
        }
        //   print(nums);
    }

    // Last round
    if (round > 1) {
        int shift = bz * (round - 1); // Bit shifting for the last round
        for (auto& [x, idx] : nums)
            bucket[x >> shift].emplace_back(x, idx);

        i = 0;
        for (auto& B : bucket) {
            for (auto& [x, idx] : B)
                nums[i++] = {x + xmin, idx}; // Adjust x back by adding xmin
            B.clear();                       // Clear bucket after usage
        }
        //    print(nums);
    }
}

class Solution {
public:
    const static int mod = 1e9 + 7;
    // Eratosthenes' Sieve
    void Sieve() {
        if (!prime.empty()) return;
        isPrime[0] = isPrime[1] = 0;
        isPrime.reserve(int(N/log(N)));
        int sqrtN=sqrt(N);
        for (int i = 2; i<=sqrtN; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = 0;
            }
        }
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]) prime.push_back(i);
        }
    }
    int dp[100001]={0};
    //computing prime score
    int prime_score(int x){
        if (x<=N && isPrime[x]) return dp[x]=1;
        if (dp[x]!=0) return dp[x];
        int xsqrt=sqrt(x), x0=x;
        int cnt=0;
        for(int p: prime){
            if (p>xsqrt) break;
            if (x%p!=0) continue;
            while (x%p==0){
                x/=p;
            }
            cnt++;
        }
        cnt+=(x>1);
        return dp[x0]=cnt;
    }

    // Modular exponentiation
    inline long long modPow(long long x, int exp) {
        long long ans= 1;
        while (exp>0) {
            if (exp&1) ans=ans*x % mod;
            x=x*x%mod;
            exp/=2;
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        Sieve();
        
        vector<int> score(n), left(n), right(n);
        for (int i=0; i< n; i++) score[i] = prime_score(nums[i]);

        int top=-1;
        for (int i=0; i < n; i++) {
            while ( top!=-1 && score[i] > score[st[top]]) top--;
            left[i] = top==-1 ? -1 : st[top];
            st[++top]=i;
        }

        top=-1;
        for (int i = n - 1; i >= 0; i--) {
            while (top!=-1 && score[i] >= score[st[top]]) top--;
            right[i] = top==-1 ? n : st[top];
            st[++top]=i;
        }

        vector<int2> num_idx(n);
        for (int i = 0; i < n; i++)
            num_idx[i] = {nums[i], i};

        radix_sort(num_idx, n);

        long long ans=1;
        for(int i=n-1; i>=0 && k>0; i--){// inverse transversal
            auto [x, idx]=num_idx[i];
            int exp=min((long long)(idx-left[idx])*(right[idx]-idx), (long long)k);
            ans=(ans*modPow(x, exp)%mod);
            k-=exp;
        }
        return ans;
    }
};


auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();