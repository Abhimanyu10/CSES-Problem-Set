#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD 1000000007
#define f first
#define s second
#define all(v) v.begin(),v.end()

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

int n,m;
const int N = 2*(1e5+1);
vector<ll> ar(N,0);
vector<int> in(N,0);
vector<int> out(N,0);
vector<int> adj[N];
vector<int> dfs_order;
int cnt = -1;

void dfs(int src,int par){
    in[src] = ++cnt;
    dfs_order.push_back(src);

    for(int i :adj[src]){
        if(i==par) continue;
        dfs(i,src);
    }
    
    out[src] = cnt;
}

vector<ll> tree(4*N,0);

void build(int l,int r,int t){
    if(l==r){
        tree[t] = ar[dfs_order[l]];
        return ;
    }
    int mid = (l+r)>>1;
    build(l,mid,2*t);
    build(mid+1,r,2*t+1);
    tree[t] = tree[2*t]+tree[2*t+1];
    return ;
}

void upd(int l,int r,int t,int ind,ll val){
    if(l==r){
        tree[t] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=ind) upd(l,mid,2*t,ind,val);
    else         upd(mid+1,r,2*t+1,ind,val);
    tree[t] = tree[2*t]+tree[2*t+1];
    return;
}   

ll qry(int l,int r,int t,int ql,int qr){
    if(l>qr || r<ql) return 0;
    if(l>=ql && r<=qr) return tree[t];
    int mid = (l+r)>>1;
    return qry(l,mid,2*t,ql,qr)+qry(mid+1,r,2*t+1,ql,qr);
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;

    for(int i= 0;i<n;i++) cin >> ar[i];

    int u,v;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }        

    dfs(0,-1);

    // cout << "DFS_ORDER\n";
    // for(int i : dfs_order){
    //     cout << 1+i << "/" << in[i] << " ";
    // }
    // cout << '\n';

    build(0,n-1,1);

    while(m--){
        int t ;
        cin >> t;
        if(t==1){
            int u,v;
            cin >> u >> v;
            u--;
            upd(0,n-1,1,in[u],v);
        }else{
            int x;
            cin >> x;
            x--;
            cout << qry(0,n-1,1,in[x],out[x]) << "\n";
        }
    }

    return 0;

}