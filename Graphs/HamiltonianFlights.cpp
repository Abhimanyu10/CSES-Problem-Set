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
#define int ll
const ll MOD =1000000007;

const int N = 20;
vi adj[N];
bool vis[N][1 << N];
int ways[1 << N];
signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);
    mem(vis);
    mem(ways);

    int n , m;
    cin >> n >> m;
    swap(n, m);
    fo(i , m){
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
    }
    
    queue<pii> q;
    q.push({0, 1});
    vis[0][1] = true;
    ways[1] = 1;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        // cout << "popped " << x.f << ' ' << "mask " << x.s << '\n';
        for(int i : adj[x.f]){
            if((x.s >> i) & 1)//means i have already visited this vertex then i will not visit it again
                continue;
            ways[x.s | (1 << i)] = (ways[x.s | (1 << i)]  % MOD + ways[x.s] %MOD) % MOD;
            q.push({i, x.s | (1 << i)});
        }
    }

    cout << ways[(1<<n)-1] % MOD << "\n";

    return 0;
}