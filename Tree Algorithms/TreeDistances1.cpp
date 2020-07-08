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
int in[N] , out[N];
vi adj[N];
void dfs(int src = 0 , int par = -1){
    for(int i : adj[src]){
        if(i == par) continue;
        dfs(i , src);
        in[src] = max(in[src] ,1 + in[i]);
    }
}

void dfs2(int src = 0 , int par = -1){
    
    int mx1 = -1 , mx2 = -1;
    for(int i : adj[src]){
        if(i == par) continue;
        if(mx1 == -1 || in[i] >= in[mx1])
            mx2 = mx1 , mx1 = i;
        else if(mx2 == -1 || in[i] > in[mx2])
            mx2 = i;
    }
    
    for(int i : adj[src]){
        if(i == par) continue;
        out[i] = 1 + out[src];
        if(i == mx1)
            out[i] = max(out[i] , mx2 == -1 ? 0 : 2 + in[mx2]);
        else
            out[i] = max(out[i] , mx1 == -1 ? 0 : 2 + in[mx1]);
        dfs2(i , src);
    }
}

signed main(){

#ifndef ONLINE_JUDGE
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    fo(i , n - 1){
        int u , v;
        cin >> u >> v;
        u--;--v;
        adj[v].pb(u);
        adj[u].pb(v);
    }

    dfs();
    dfs2(); 

//    fo(i , n) cout << in[i] << " " ;
//    cout << '\n';
//
//    fo(i , n) cout << out[i] << " " ;
//    cout << '\n';
    fo(i , n) cout << max(in[i] , out[i]) << " ";
    cout << '\n';

    return 0;

}

