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

const int N = 40;
vi ar(N, 0);
unordered_map<ll, int> a , b;

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    a.max_load_factor(0.25);
    // b.max_load_factor(0.25);
    a.reserve(1e6);
    // b.reserve(1e6);
    int n , s;
    cin >> n >> s;
    ll ans = 0;

    fo(i, n) cin >> ar[i];
    int p = n >> 1;
    // deb(p);
    fo(i , 1 << (n - p)){
        ll x = 0;
        fo(j , (n - p)){
            if((i >> j) & 1){
                x += ar[j];
            }
        }
        a[x] += 1;
    }
    // ans += a[s];

    reverse(ar.begin(), ar.begin() + n);
    fo(i , 1 << p){
        ll x = 0;
        fo(j , p){
            if((i >> j) & 1){
                x += ar[j];
            }
        }
        ans += a[s - x];
    }
    cout << ans << '\n';

    return 0;
}