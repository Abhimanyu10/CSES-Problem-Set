//@author :: Abhimanyu Chauhan

// #pragma GCC target("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


#define oo			INT_MAX/2
#define f			first
#define sz(a)  ((int)(a).size())
#define s			second
#define present(c,x) ((c).find(x)!=(c).end())
#define all(v)		v.begin(),v.end()
#define pii 			pair<int,int>
#define pil 		pair<int,long long>
#define pll 		pair<long long , long long>
#define vpii 		vector<pii>
#define vpil 		vector<pil>
#define vpll 		vector<pll>
#define eb			emplace_back
#define mem(x) 			memset(x , 0 , sizeof(x))
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>
#define vll			vector<ll>
#define deb(x)		cout << #x << " " << x << endl

using namespace std;
using ll  = long long;
using lld = long double;
using l64 = int64_t;

const ll MOD =1000000007;

const int N = 1e5 + 1;
vi adj[N];
int n, m;
vector<bool> vis(N  , false);
deque<int> dq;

void dfs(int src){
    vis[src] = true;
    for(int i : adj[src]){
        if(vis[i])
            continue;
        dfs(i);
    }
    dq.push_front(src);
}

void top_sort(){
    fo(i, n) if (!vis[i]) dfs(i)  ;
}
int indeg[N];
int dp[N];

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif
    mem(indeg);
    mem(dp);
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    fo(i , m){
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        // adj[v].pb(u);
        indeg[v]++;
    }

    top_sort();

    dp[0] = 1;
    for(int i : dq){
        // if(indeg[i] == 0)
        //     dp[i] = 1;
        for(int j : adj[i]){
            dp[j] = (dp[j] % MOD + dp[i] %  MOD) % MOD;
        }
    }
    cout << dp[n - 1] << "\n";

    return 0;
}