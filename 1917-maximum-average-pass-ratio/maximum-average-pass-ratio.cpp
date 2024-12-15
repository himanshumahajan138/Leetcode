using info = tuple<double, int, int>;
vector<info> A;
class Solution {
public:
    static inline double incr(int p, int q) {
        return (q - p) / (q * (q + 1.0));
    }
    static double maxAverageRatio(vector<vector<int>>& classes, int k) {
        const int n = classes.size();
        A.resize(n);
        double sum = 0.0;
        for (int i = n - 1; i >= 0; i--) {
            int p = classes[i][0], q = classes[i][1];
            sum += (double)p / q;
            A[i] = {incr(p, q), p, q};
            if (A[i]>A[n-1]) swap(A[i], A[n-1]);//keep A[n-1] largest
        }
        make_heap(A.begin(), A.end()-1);

        while (k>0) {
            pop_heap(A.begin(), A.end()-1);
            auto [r1, p1, q1]=A[n-1];
            double r2=get<0>(A[n-2]);
            sum+=r1;
            int s=1;
            double rr;
            for(; s<k; s++){
                rr=incr(p1+s, q1+s);
                if (rr<r2) break;
                else sum+=rr;// add rr to sum
            }
            k-=s; //decrease k by s
            if (k==0) break;
            A[n-1]=A[n-2];
            A[n-2]={rr, p1+s, q1+s};
        //    if (A[n-1]<A[n-2]) swap(A[n-2], A[n-1]);
            push_heap(A.begin(), A.end()-1);
        }

        return sum / n;
    }
};