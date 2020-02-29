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
vi adj[N] , id(N , -1) , onStack(N , 0) , low(N , -1);
int timer = -1;
vector<int> comp_starts;
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
        comp_starts.pb(src);
        while(true){
            int x = st.top();
            st.pop();
            onStack[x] = 0;
            if(x == src)
                break;
        }
    }
}

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m;
    cin >> n >> m;
    fo(i , m){
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
    }

    stack<int> st;
    fo(i , n){
        if(id[i] == -1)
            dfs(i, st);
    }

    if(comp_starts.size() > 1){
        cout << "NO\n" << ++comp_starts[0] << " " << ++comp_starts[1] << "\n";
    }else{
        cout << "YES\n";
    }

    return 0;

}