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

const int N = 1e5 + 10;
vi adj[N];
vi dis(N, 0);
vi par(N, 0);
vector<bool> vis(N, false);
deque<int> dq;

int n, m;

void dfs(int src){
    vis[src] = true;
    for(int i : adj[src]){
        if(!vis[i])
            dfs(i);
    }
    dq.push_front(src);
}

void top_sort(){
    fo(i, n) if (!vis[i]) dfs(i);
}

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    fo(i , m){
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
    }

    top_sort();
    fo(i, n) par[i] = i;
    for(int i : dq)
        for(int j : adj[i])
            if(dis[j] < 1 + dis[i])
                dis[j] = 1 + dis[i]  , par[j] = i;


    int des = -1;
    int maxi = 0;
    fo(i, n) if (dis[i] > maxi) maxi = dis[i], des = i;
    if(des == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vi ans;
    while(par[des] != des){
        ans.pb(des);
        des = par[des];
    }
    ans.pb(des);
    reverse(all(ans));
    cout << ans.size() << "\n";
    for(int i : ans)
        cout << i + 1 << " ";
    cout << '\n';

    return 0;
}