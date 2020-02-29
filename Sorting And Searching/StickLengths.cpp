//https://cses.fi/problemset/task/1074
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
const int N = 2e5+100;
vector<ll> ar(N , 0);
int main(){
#define int ll
#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    fo(i , n){
        cin >> ar[i];
    }
    if(n==1){
        cout << "0\n"; return 0;
    }

    sort(ar.begin() , ar.begin()+n);
    int ans = 0;
    int x = n>>1;

    fo(i , n){
        ans+=abs(ar[i]-ar[x]);
    }

    if(n&1){
        cout << ans << '\n';
        return 0;
    }

    int ans3 = (x-1 >= 0 ? 0 : oo);
    int ans2 = (x+1 < n ? 0 : oo) ;
    fo(i , n){
        if(x+1<n)
        ans2+=abs(ar[i]-ar[x+1]);
        if(x-1>=0)
        ans3+=abs(ar[i]-ar[x-1]);
    }

    cout << min({ans , ans2 , ans3}) << "\n";
    
    return 0;

}