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
const ll MOD =1000000007;

const int N = 1e5 + 10;
vpii adj[N];
int dis[N][10];
const int oo = 1e14;

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m , k;
    cin >> n >> m >> k;
    fo(i , m){
        int u , v , w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
    }
    
    auto cmp = [](pii a, pii b) {
        return a.s > b.s;
    };

    fo(i, n) fo(j, k) dis[i][j] = oo;

    priority_queue<pii, vpii, decltype(cmp)> pq(cmp);
    pq.push({0, 0});
    dis[0][0] = 0;

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        for(auto i : adj[x.f]){
            sort(dis[i.f], dis[i.f] + k, greater<int>());
            fo(j , k){
                if(dis[i.f][j] >= i.s + x.s){
                    dis[i.f][j] = i.s + x.s;
                    pq.push({i.f , dis[i.f][j]});
                    break;
                }
            }
        }
    }
    sort(dis[n - 1], dis[n - 1] + k);
    fo(i , k) cout << dis[n-1][i] << " ";


    return 0;
}