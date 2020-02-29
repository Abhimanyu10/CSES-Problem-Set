// #pragma GCC target("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#define MOD 1000000007

#include<bits/stdc++.h>

using namespace std;
using ll  = unsigned long long;
using lld = long double;
using vll = int64_t;

const int N = 2*(1000000+100);
ll c[N];
int n;
vector<int> adj[N];
vector<int> ans(N,0);
set<int> s1;

void dfs(int src,int par){
    set<int> t1;
    t1.insert(c[src]);
    for(int i : adj[src]){
        if(i==par) continue;
        dfs(i,src);
        if(s1.size()>t1.size()) swap(s1,t1);
        for(int j : s1) t1.insert(j);
    }
    ans[src] = t1.size(); 
    swap(s1,t1);
    return ;
}

int32_t main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) cin >> c[i];
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,-1);

    for(int i =0;i<n;i++) cout << ans[i] << ((i<n-1)?" ":"\n");

    return 0;
}