#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

#define MOD 1000000007
#define f first
#define s second
#define all(v) v.begin(),v.end()

using namespace std;
using ll  = long long
using lld = long double;
using vll = int64_t;

#define int ll

const int N = 1e5+1;
vector<pair<int,ll>> adj[N];
bool vis[N];
ll dis[N];
int n,m;

deque<int> topo;

void dfs(int src){
    vis[src] = true;
    for(auto i : adj[src]) if(!vis[i.f]) dfs(i.f);
    topo.push_front(src);
    return;
}

int32_t main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;


    for(int i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        adj[u].push_back({v,w});
    }

    fill(vis,vis+n,false);
    fill(dis,dis+n,LONG_MAX/3);

    for(int i = 0;i<n;i++){
        if(vis[i]) continue;
        dfs(i);
    }

    bool mark[n];
    int par[n];
    fill(mark,mark+n,false);
    dis[topo[0]] = 0;
    par[topo[0]] = -1;
    for(int i : topo) for(auto j : adj[i])
        
        if(dis[j.f]>dis[i]+j.s){
            dis[j.f] = dis[i]+j.s ; 
            par[j.f] = i;
        }
        else if( dis[j.f] == dis[i]+j.s ){
            mark[j.f] = true;
        } 
     
    cout << '\n';

    for(int i=0;i<n;i++){
        cout << dis[i] << " ";
    }

    vector<int> ans;
    int i = par[n-1];
    ans.push_back(n);
    while(i!=-1){
        if(mark[i])
        ans.push_back(i+1);
        i = par[i];
    }

    sort(all(ans));
    cout << ans.size() << "\n";
    for(int j : ans) cout << j << " ";

    return 0;

}
