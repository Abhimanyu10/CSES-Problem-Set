//@author :: Abhimanyu Chauhan

// #pragma GCC target("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


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

#define int ll
const int oo = 1e15;
const ll MOD =1000000007;
const int N = 1e5 + 10;
bool vis[N];
vi dis(N , oo);
vpii adj[N];
signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m;
    cin >> n >> m;

    fo(i , m){
        int u , v , w;
        cin >> u >> v >> w;
        u--;v--;
        adj[u].pb({v , w});
    }
    
    auto cmp = [](pii a, pii b) {
        return a.s > b.s;
    };
    

    priority_queue<pii, vpii, decltype(cmp)> pq(cmp);
    pq.push({0,0});
    dis[0] = 0;

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        
        if(vis[x.f]) 
            continue;
        vis[x.f] = true;

        for(auto i : adj[x.f]){
            if(i.s + x.s <= dis[i.f]){
                dis[i.f] = i.s + x.s;
                pq.push(make_pair(i.f , dis[i.f]));
            }
        }
    }

    fo(i , n) cout << dis[i] << " ";
    cout << '\n';

    return 0;

}