//@author :: Abhimanyu Chauhan

#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define oo			INT_MAX/2
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)		for(int i=k;i<n;i++)
#define deb(x)			cout << #x << " " << x << endl

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

template<typename T>
istream& operator >> (istream& in , vector<T> &ar){
    for (int i = 0 ; i < (int) ar.size() ; i++) in >> ar[i];
return in;
}

template<typename T>
ostream& operator << (ostream& out , vector<T> &ar){
    for (int i = 0 ; i < (int) ar.size() ; i++) out << ar[i];
return out;
}

vector<ll> ar(2e5+10 , 0);
int main(){
#define int ll
#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n , t;
    cin >> n >> t;
    for(int i=0;i<n;i++)cin >> ar[i];

    auto fun = [&](const ll &x){
        vll ans = 0;
        vll xx = x;
        for(int i=0;i<n;i++){
            ans += (xx/(vll)ar[i]);
            if(ans >= t) return true;
        }
        return ans >= (vll)t;
    };

    ll l = 0;
    ll h = 1e18+100;
    while(l+1 < h){
        ll mid = (l+h)>>1;
        // deb(mid);
        if(fun(mid)) h = mid;
        else l = mid;
    }
    // cout << fun(432022746206282698) << "\n";
    cout << h << '\n';

    return 0;

}