#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD 1000000007
#define f first
#define s second
#define all(v) v.begin(),v.end()

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

ll pow(ll a , ll b){
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll k = pow(a,b/2)%MOD;
    if(b%2==1){
        return (k*k)%MOD*a%MOD;
    }else{
        return (k*k)%MOD;
    }
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        ll a,b;
        cin >> a >> b;
        cout << pow(a,b) << "\n";
    }

    return 0;
}