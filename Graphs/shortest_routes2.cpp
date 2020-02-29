//@author :: Abhimanyu Chauhan

// #pragma GCC target("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


// #define oo			INT_MAX/2
#define f			    first
#define sz(a)           ((int)(a).size())
#define s			    second
#define present(c,x)    ((c).find(x)!=(c).end())
#define all(v)		    v.begin(),v.end()
#define pii 			pair<int,int>
#define pil 		    pair<int,long long>
#define pll 		    pair<long long , long long>
#define vpii 	    	vector<pii>
#define vpil 		    vector<pil>
#define vpll 		    vector<pll>
#define eb			    emplace_back
#define mem(x) 			memset(x , 0 , sizeof(x))
#define pb			    push_back
#define fo(i,n)		    for(int i=0;i<n;i++)
#define Fo(i,k,n)	    for(int i=k;i<n;i++)
#define vi			    vector<int>
#define vll			    vector<ll>
#define deb(x)		    cout << #x << " " << x << endl

using namespace std;
using ll  = long long;
using lld = long double;
using l64 = int64_t;

#define int ll
const ll MOD = 1000000007;
const int oo = 1e14;
const int N  = 501;

int dp[N][N];

int n,m,q;

void build(){
    fo(i , n)
        fo(j , n)
            fo(k , n)
                dp[j][k] = min(dp[j][i] + dp[i][k], dp[j][k]);
}

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> q;
    fo(i, n) fo(j, n) if (i == j) dp[i][j] = 0; else dp[i][j] = oo;

    fo(i , m){
        int u , v , w;
        cin >> u >> v >> w;
        u--;
        v--;
        dp[u][v]  = dp[v][u] = min({dp[u][v] , dp[v][u] , w});
    }

    build();

    while(q--){
        int src , des;
        cin >> src >> des;
        src--;
        des--;
        cout << (dp[src][des]>=oo?-1:dp[src][des]) << "\n";
    }

    return 0;
}