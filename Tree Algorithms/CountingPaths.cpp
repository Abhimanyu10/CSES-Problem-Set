#include<bits/stdc++.h>

#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;

const int N = 2e5 + 100;
vi adj[N] , in(N , 0) , out(N , 0);
int up[N][20];
int t = -1;
void dfs(int src = 0 , int par = 0){
    t++;
    in[src] = t;
    up[src][0] = par;
    for(int i = 1 ; i < 20 ; i++) 
        up[src][i] = up[up[src][i - 1]][i - 1];
    for(int i : adj[src]){
        if(i == par) continue;
        dfs(i , src);
    }
    out[src] = t;
}
 
//tells if u is ances of v
bool is_ances(int u , int v){
    if(u == 0)
        return 1;
    if(in[u] <= in[v] && out[u] >= out[v])
        return 1;
    return 0;
}
 
int lca(int u , int v){
    if(is_ances(u , v))
        return u;
    if(is_ances(v , u))
        return v;
    for(int i = 19 ; i >= 0 ; i--){
        if(!is_ances(up[u][i] , v))
            u = up[u][i];
    }
    return up[u][0];
}

int ans[N] , ar[N];
int dfs2(int src = 0 , int par = 0){
    int sum = 0;
    for(int i : adj[src]){
        if(i == par)
            continue;
        sum += dfs2(i , src);
    }
    sum += ar[src];
    ans[src] = sum;
    //cout << "ans[src]" << sum << '\n';
    return sum;
}
signed main(){

#ifndef ONLINE_JUDGE
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m;
    cin >> n >> m;
    fo(i , n - 1){
        int u , v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs();

    while(m--){
        int u , v;
        cin >> u >> v;
        u--;v--;
        int x = lca(u , v);
        if(x != 0){
            ar[up[x][0]]--;
        }
        ar[x]--;
        ar[u]++;
        ar[v]++;
    }
   
    //for(int i = 0 ; i < n ; i++) cout << ar[i] << " "; cout << '\n'; 
    dfs2();
        
    for(int i = 0 ; i < n ; ++i)
        cout << ans[i] << " ";
    return 0;

}

