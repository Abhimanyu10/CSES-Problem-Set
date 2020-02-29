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

const int N = 102;
int ar[N];
vector<int> dp(1e6+1,0); 
int n;

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int x;
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
    }

    sort(ar,ar+n);

    dp[0] = 1;
    for(int i=1 ;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(ar[j] <= i) {
                dp[i] += dp[i-ar[j]];
                dp[i] %= MOD;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << dp[i] << " ";
    // }
    cout << dp[x] << "\n";
    
    return 0;
}