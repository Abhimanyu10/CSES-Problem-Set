//https://cses.fi/problemset/result/209482/
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
// const int N = 2e5+10;
// vector<int> ar(N,0);
int main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    map<ll,ll> hm;
    hm[0]++;
    ll tot = 0;
    fo(i , n) {
        ll t;
        cin >> t;
        tot += t % n;
        tot = (tot % n + n )%n;
        hm[tot]++;
    }
    ll ans = 0;
    for(auto i : hm){
        ans += i.s*(i.s-1)/2;
    }

    cout << ans << '\n';
    return 0;

}