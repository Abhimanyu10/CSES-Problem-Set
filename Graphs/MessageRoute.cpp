//@author :: Abhimanyu Chauhan

// #pragma GCC target("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


#define oo			INT_MAX/2
#define f			first
#define sz(a)       ((int)(a).size())
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
#define mem(x) 		memset(x , 0 , sizeof(x))
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

const int N = 1e5 + 10;


vi adj[N] , dis(N , 0) , par(N , 0);
vector<bool> vis(N, false);

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m ;
    cin >> n >> m;
    fo(i , m){
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> q;
    q.push(0);
    vis[0] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i : adj[x]){
            if(!vis[i]){
                vis[i] = true;
                dis[i] = 1 + dis[x];
                par[i] = x;
                q.push(i);
            }
        }
    }

    if(!vis[n-1]){
        cout << "IMPOSSIBLE\n";
    }else{
        vector<int> ans;
        ans.pb(n - 1);
        int j = n - 1;
        while(par[j]!=j){
            j = par[j];
            ans.pb(j);
        }

        reverse(all(ans));
        
        cout << sz(ans) << "\n";
        
        for(auto i : ans){
            cout << 1+i << " ";
        }

        cout << "\n";
    }

    return 0;
}