#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

const ll N = 2*(1e5+1);
vector<int> adj[N];
ll n;
vector<ll> lvl(N,0),sz(N,0),sum(N,0);

void dfs(int src,int par){
    sz[src]++;
    for(int i : adj[src]){
        if(i==par) continue;
        lvl[i] = lvl[src]+1;
        dfs(i,src);
        sz[src]+=sz[i];
    }
}

void dfs2(int src,int par,ll s){
    sum[src] = s;
    for(int i : adj[src]){
        if(i==par) continue;
        dfs2(i,src,s+(n-2LL*sz[i]));
    }
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,-1);
    
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans+=lvl[i];
    }
    
    dfs2(0,-1,ans);

    for(int i=0;i<n;i++){
        cout << sum[i] << " ";
    }

    return 0;
}