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
const int N = 1e5+1;
vector<vector<int>> dp(2,vector<int>(N,0));

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,x;
    cin >> n >> x;
    int cost[N];
    int val[N];
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    for(int i =0;i<n;i++){
        cin >> val[i];
    }

    for(int i=0;i<n;i++){
        for(int j =0 ;j<=x;j++){
            if(i==0){
                if(cost[i]<=j) dp[0][j] = val[0]; 
                continue;   
            }
            if(cost[i]>j)
                dp[i%2][j] = dp[(i-1)%2][j];
            else
                dp[i%2][j] = max(dp[(i-1)%2][j],dp[(i-1)%2][j-cost[i]]+val[i]);
        }
    }
    cout << dp[(n-1)%2][x] << "\n";

    return 0;

}