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
vi ans , adj[N];
bool vis[N];

bool dfs(vi &st , int src , int par){
    st.push_back(src);
    vis[src] = true;
    bool ok = false;
    for(int i : adj[src]){
        if(i == par)
            continue;
        if(!vis[i]){
            ok |= dfs(st , i, src);
            if(ok)
                return true;
        }
        else{
            if(st.size()<=1)
                continue;
            ans.clear();
            ans.pb(i);
            if(!st.empty())
            while(st.back()!=i){
                ans.pb(st.back());
                // deb(st.back());
                st.pop_back();
                if(st.empty())
                    break;
            }
            ans.pb(i);
            cout << sz(ans) << "\n";
            for(int i : ans){
                cout << 1+i << " ";
            }
            cout << "\n";
            return true;
        }
    }
    st.pop_back();
    return ok;
}

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u , v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi st;
    bool ok = false;
    fo(i , n){
        ok|=dfs(st, i, -1);
        if(ok)
            break;
    }
    if(!ok)
        cout << "IMPOSSIBLE\n";
    return 0;
}