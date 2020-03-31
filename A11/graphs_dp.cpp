#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define pb push_back
#define vll vector<ll>
class Disjoint_Set_Tree{
    private:
    vi root, rank, sum ,depth;
    vvi LCA, adj;
    int x,y,n,p,lg;
    ll count;
    vll f;
    public:
    Disjoint_Set_Tree(int n, int num){
        root = vi(n,0);
        depth = vi(n,0);
        rank = vi(n,0);
        sum = vi(n,0);
        lg = 18; 
        LCA = vvi(lg+1, vector<int>(n,0));
        adj = vvi(n, vector<int>());
        f = vll(n,0);
        this->n = num;
        count=0;
    }
    void take_input(){
        int u,v;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    void make_set(){
        for(int i=1;i<=n;i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    int find(int x){
        if(root[x] == x){
            return x;
        }
        else{
            root[x] = find(root[x]);
            return root[x];
        }
    }    

    int anc(int x){
        return find(LCA[0][find(x)]);
    }

    int reduce(int x){
        x = find(x);
        int y = anc(x);
        count += (sum[x]*(ll)sum[x] - f[x] - rank[x]) / 2 * rank[y];
        count += ((n- sum[x]) * (ll)(n - sum[x]) - (f[y] - sum[x] * (ll) sum[x] + (n - sum[y]) * (ll)(n - sum[y])) - rank[y])/ 2 * rank[x];
        f[y] = f[y] - sum[x] * (ll) sum[x] + f[x];
        root[x] = y;
        rank[y] += rank[x];
       // cout<<count<<" ";
        return y;
    }
    void initialize(int node, int root){
        sum[node] = 1;
        LCA[0][node] = root;
        for(auto i: adj[node]){
            if(i == root) 
                continue;
            depth[i] = depth[node] + 1;
            initialize(i, node);
            f[node]+= sum[i]*(ll)sum[i];
            sum[node]+= sum[i];
        }
        count+=(sum[node] - 1)*(ll)(n- sum[node]);
        count+=((sum[node]-1)*(ll)(sum[node]-1)- f[node])/2;

   // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    }
    
    void lca_initialize(){
        for(int i=1;i<= lg;i++){
            for(int j =1; j<=n;j++){
                LCA[i][j] = LCA [i-1][LCA[i-1][j]];
            }
        }
    }
    int least_common_ancestor(int x, int y){
        if(depth[x] < depth[y]){
            int temp = x;
            x = y;
            y = temp;
        }
        int difference = depth[x] - depth[y];
        for(int i=0; i<= lg; i++){
            if(difference & (1<<i)){
                x = LCA[i][x];
            }
        }
        if(x==y){
            return x;
        }
        for(int i=lg; i>=0;i--){
            if(LCA[i][x] != LCA[i][y]){
                 x = LCA[i][x];
                 y = LCA[i][y];
            }
        }
        
        return LCA[0][x];
    }
    void edge_addition(){
        cin>>x>>y;
        x = find(x);
        y = find(y);
        //cout<<x<<" "<<y<<" ";
        if(x == y){
            print();
            return;
        }
        int r = find(least_common_ancestor(x,y));
        cout<<r<<" ";
        while(x != r){
            x = reduce(x);
        }
        while(y != r){
            y = reduce(y);
        }
        print();
    }
    void edge_addition_m(int m){
        while(m--){
            edge_addition();
        }
    }
    void print(){
        printf("%lld\n", 2 * count);
    }

};

int main(){
    int n;cin>>n;
    Disjoint_Set_Tree t(2e5 + 6, n);
    t.take_input();
    t.make_set();
    t.initialize(1,0);
    t.lca_initialize();
    int m;cin>>m;
    t.print();
    t.edge_addition_m(m);
    return 0;
}
