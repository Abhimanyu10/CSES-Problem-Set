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

//idea : simple store sub tree size 
const int N = 2e5 + 10;
vi adj[N];
vi sub(N ,0);

void dfs(int src , int par){
    for (int i : adj[src]){
        if(i == par) continue;
        dfs(i, src);
        sub[src] += sub[i];
    }
    sub[src] += 1;
}

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    Fo(i , 1 , n) {
        int u;
        cin >> u ;
        u--;
        adj[u].pb(i);
        adj[i].pb(u);
    }

    dfs(0, 0);
    fo(i, n) cout << sub[i]-1 << " ";

    return 0;

}