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

const int N = 2e5 + 10;
vi adj[N];
int up[N][20];

void dfs(int src = 1, int par = -1){
    up[src][0] = par;
    for(int i = 1 ; i < 20 ; i++)
        up[src][i] = up[src][i - 1] == -1 ? -1 : up[up[src][i - 1]][i - 1];
    for(int i : adj[src]){
        if(i == par) continue;
        dfs(i , src);
    }
}

void lift(int & u , int x){
    for(int i = 19 ; i >= 0 ; i--)
        if((x >> i) & 1){
            if(u == -1)
                return;
            u = up[u][i];
        }
}

signed main(){

#ifndef ONLINE_JUDGE
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);


    int n , q;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i) {
        if(i == 1) continue;
        int x ;
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    dfs();
    while(q--){
        int u , x;
        cin >> u >> x;
        lift(u , x);
        cout << u << "\n" ;
    }

    return 0;

}

