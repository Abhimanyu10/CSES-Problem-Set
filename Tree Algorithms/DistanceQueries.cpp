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

const int N = 2*(1e5+1);
vector<int> adj[N] , in(N,0) , out(N,0) , lvl(N,0);

vector<vector<int>> up(N,vector<int>(20,0));
int L;

int cnt = -1;


void dfs(int src,int par){

    in[src] = ++cnt;
    up[src][0] = par;
    if(par!=src){
        lvl[src] = 1+lvl[par];
    }

    for(int i = 1; i<L ;i++) up[src][i] = up[up[src][i-1]][i-1];  

    for(int i : adj[src]){
        if(i==par) continue;
        dfs(i,src);
    }
    
    out[src] = ++cnt;
}

bool is_ances(int u,int v){
    return in[u] <= in[v] && out[u] >= out[v];  
}

int lca(int u,int v){
    if(is_ances(u,v)) return u;
    if(is_ances(v,u)) return v;

    for(int i = L-1;i>=0;i--) 
        if(!is_ances(up[u][i],v)) u = up[u][i];
    
    return up[u][0];
}



int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i = 0 ; i < n-1 ; i++){

        int u , v ; cin >> u >> v;
        u-- ; v-- ;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    L = 0;
    while(1<<L < n) L++;

    lvl[0] = 0;
    dfs(0,0);

    while(m--){
        int u,v;
        cin >> u >> v;
        auto p  = lca(u-1,v-1);
        cout << lvl[u-1] + lvl[v-1] - 2*lvl[p] << "\n";
    }

    return 0;
}