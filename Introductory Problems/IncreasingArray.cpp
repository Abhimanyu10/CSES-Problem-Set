// https://cses.fi/problemset/task/1094

#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n; cin >> n;

    int curr_max ;
    cin >> curr_max;
    ll ans = 0;
    for(int i=1;i<n;i++) {
        int t;
        cin >> t;
        if(curr_max-t>=0)
            ans = ans + ((ll)curr_max-(ll)t);

        curr_max = max(curr_max,t);
    }
    cout << ans << "\n";
    return 0;

}