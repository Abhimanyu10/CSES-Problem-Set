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

const int N = 1e5+1;
vector<int> val(N,0) , adj[N] , on_stack(N,0) , id(N,-1) , low(N,-1);

int cnt = 0;
int cc[N];
int tt = 0;
void dfs(int src,stack<int> &st){
    low[src] = id[src] = cnt++;
    on_stack[src] = 1;
    st.push(src);
    
    for(int i : adj[src]){
        if(id[i] == -1)
            dfs(i,st);  
        if(on_stack[i] == 1)
            low[src] = min(low[src],low[i]);
    }
    
    if(low[src]==id[src]){
        ++tt;
        while(true){
            auto p = st.top();
            st.pop();
            on_stack[p] = 0;
            cc[p] = tt;
            if(p==src) break; 
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u ,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    stack<int> st;
    for(int i  = 0;i<n;i++){
        if(id[i]==-1)
            dfs(i,st);
    }

    cout << tt << "\n";
    fo(i, n) cout << cc[i] << " ";
    cout << "\n";

    return 0;
}