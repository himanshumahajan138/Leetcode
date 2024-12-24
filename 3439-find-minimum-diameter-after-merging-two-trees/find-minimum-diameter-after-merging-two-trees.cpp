const int N=100000;
int deg[N]={0};
vector<int> adj[N];
class Solution {
public:
    // modify Kahn's algorithm for undirected graph
    static int diameter(vector<vector<int>>& edges) {
        const int n=edges.size()+1;
        fill(deg, deg+n, 0);
        fill(adj, adj+n, vector<int>());
        for (auto& e : edges) {
            const int v=e[0], w=e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
            deg[v]++, deg[w]++;// degree count
        }
        int q[N];
        int front=0, back=0;
        for (int i=0; i < n; i++)
            if (deg[i] == 1)// Push leaves to q
                q[back++]=i;

        int level=0, left=n;
        //inward toward center
        for (; left>2; level++) { //may only 2 leaf nodes
            int qz=back-front;
            left-=qz;
            for (int i=0; i<qz; i++) {
                int v=q[front++];
                for (int w : adj[v]) {
                    // remove edge (v, w) s.t. w being a leaf
                    if (--deg[w]==1) q[back++]=w;
                }
            }
        }
    //    cout<<"left="<< left<<",level="<<level<<endl;
        return (left==2)?2*level+1:2*level;

    }

    static int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                         vector<vector<int>>& edges2) {
        int d1=diameter(edges1), d2=diameter(edges2);
        return max({d1, d2, (d1+1)/2+(d2+1)/2+1});
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();