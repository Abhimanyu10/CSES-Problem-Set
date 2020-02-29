#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2*(1e5+1);
vector<int> in(N,0);
vector<int> out(N,0);
vector<int> dfs_order;
vector<ll> ar(N,0);
vector<int> adj[N];

//------------------------BIT--------------------------------

vector<ll> bit(N+1,0);
vector<ll> lazy(N+1,0);

void range_upd(int l,int r,ll val){
    while(l<N){
        lazy[l] += val;
        l += (l&-l);
    }

    r+=1;
    while(r<N){
        lazy[r] -= val;
        r += (r&-r);
    }
}

void point_upd(int x, ll val){
    while(x<N){
        bit[x]+=val;
        x += (x&-x);
    }
}

ll qry(int x){
    ll sum = 0;
    while(x>0){
        sum+=bit[x];
        x -= (x&-x);
    }
    return sum;
}

ll qry_lazy(int x){
    ll sum = 0;
    while(x>0){
        sum+=lazy[x];
        x -= (x&-x);
    }
    return sum;
}

ll get(int x){
    return qry(x)-qry(x-1)+qry_lazy(x);
}

//---------------------------------------------------------------


int tc;
int n;
int q;
int cnt = -1;

void dfs(int src,int par){
    in[src] = ++cnt; 
    dfs_order.push_back(src);
    
    for(int i: adj[src]){
        if(i==par) continue;
        ar[i]+=ar[src];
        dfs(i,src);
    }
    
    out[src] = cnt;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> q;
    ll tmp[n];
    
    for(int i=0;i<n;i++){ cin >> ar[i]; tmp[i] = ar[i]; }
   
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    dfs(0,-1);

    for(int i=0;i<n;i++){
        point_upd(i+1,ar[dfs_order[i]]);
    }

    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int x; ll val;
            cin >> x >> val;
            x-=1;
            range_upd(in[x]+1,out[x]+1,val-tmp[x]);
            tmp[x] = val;
        }else{
            int x;
            cin >> x;
            x-=1;
            cout << get(in[x]+1) << "\n";
        }
    }


    // cout << "DEBUG\n";
    // for(int i=0;i<n;i++) cout << dfs_order[i] << " ";
    // cout << "\n";
    // for(int i=0;i<n;i++) cout << lazy[i] << " ";
    // cout << "\n";

    return 0;

}