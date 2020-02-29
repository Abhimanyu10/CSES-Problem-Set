//@author :: Abhimanyu Chauhan

// #pragma GCC target("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>

#define int ll
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

int n, m;

deque<int> dq;
const int N = 1e5 + 10;
vi adj[N] , id(N , -1) , onStack(N , 0) , low(N , -1);
vi dp(N, 0) , coins(N , 0);
int timer = -1;
vector<int> comp_starts;
vi comp[N];
vi par(N, 0);

void dfs(int src , stack<int> &st){
    id[src] = low[src] = ++timer;
    st.push(src);
    onStack[src] = 1;
    
    for(int i : adj[src]){
        if(id[i] == -1)
            dfs(i, st);
        if(onStack[i])
            low[src] = min(low[i], low[src]);
    }

    if(id[src] == low[src]){
        while(true){
            int x = st.top();
            par[x] = src;
            dp[src] += coins[x];
            comp[src].pb(x);
            st.pop();
            onStack[x] = 0;
            if(x == src)
                break;
        }
        coins[src] = dp[src];
    }
    dq.push_front(src);
}

void top_sort(){
    stack<int> st;
    fo(i, n) if (id[i] == -1) dfs(i , st);
}

vector<bool> vis(N, false);

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    fo(i, n) cin >> coins[i];
    fo(i , m){
        int u , v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
    }

    top_sort();
    // fo(i, n) cout << 1 + i << " " << 1+par[i] << "\n";

    // for (auto x : dq)
    //         cout << 1 + x << " ";
    // cout << '\n';
    // fo(i, n) cout << dp[i] << " ";
    // cout << '\n'; 
    for(int i : dq){
        if(vis[i])
            continue;
        // deb(i);
        
        vis[i] = true;
        unordered_set<int> ed;
        for(int j : adj[i])
            ed.insert(par[j]);
        for(int j : comp[i]){
            vis[j] = true;
            for(int k : adj[j]){
                if(!vis[par[k]])
                ed.insert(par[k]);
            }
        }

        // cout << "QRY " << 1+i << "\n";


        for(int j : ed){
            if(vis[j] || i==j)
                continue;
            // deb(j);
            // cout << "par " << 1+j << " " << 1+par[j] << "\n";
            dp[j] = max(dp[j], dp[i] + coins[j]);
            // deb(dp[j]);
        }
    }

    // fo(i , n){
        cout << *max_element(dp.begin(), dp.begin() + n) << "\n";
    // }

    return 0;
}