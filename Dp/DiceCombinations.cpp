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
#define eb			emplace_back
#define pb			push_back

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

ll dp[1000000+2];

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=6;j++){
            if(i-j>=0)
            dp[i]+=dp[i-j];
            dp[i] %= MOD;
        }
    }
    // for(int i=0 ;i<10;i++) cout << dp[i] << " ";
    // cout << '\n';
    cout << dp[n] << "\n";
    return 0;

}