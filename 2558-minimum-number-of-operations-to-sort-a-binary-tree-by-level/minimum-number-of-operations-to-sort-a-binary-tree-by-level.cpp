const int N=50001;
class Solution {
public:
    inline static int dfs(int i, int* idx, bitset<N>& viz){
    //    cout<<i<<"->";
        if (viz[i]) return 0;
        viz[i]=1;
        int j=idx[i];
        return 1+dfs(j, idx, viz);
    }
    static int minimumOperations(TreeNode* root) {
        TreeNode* q[N];
        int front=0, back=0;
        q[back++]=root;
        int swaps=0;
        while(back-front!=0){
            int qz=back-front; 
            qz=(qz>0)?qz: qz+N;
            int* idx=(int*)alloca(qz*sizeof(int));
            iota(idx, idx+qz, 0);
            int* arr=(int*)alloca(qz*sizeof(int));
            for(int i=0; i<qz; i++){
                auto node=q[front];
                if (++front==N)  front=0;
                arr[i]=node->val;
                if(node->left) {
                    q[back]=node->left;
                    if (++back==N)  back=0;
                }
                if(node->right) {
                    q[back]=node->right;
                    if (++back==N)  back=0;
                }
            }
            // each value is unique, no need for stable_sort
            sort(idx, idx+qz, [&](int i, int j){
                return arr[i]<arr[j];
            });
            // cycle length count
            bitset<N> viz=0;
        //    cout<<"\n----\n";
            for(int i=0; i<qz; i++){
                if (!viz[i]) swaps+=dfs(i, idx, viz)-1;
            }
        }
        return swaps;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();