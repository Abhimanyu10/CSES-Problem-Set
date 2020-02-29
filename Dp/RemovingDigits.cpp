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

const int N = 1e6+1 , oo = INT_MAX/10;

int dp[N]; 

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int x;
    cin >> x;
    dp[0] = 1;
    fill(dp+1,dp+x+1,oo);
    for(int i=1;i<=x;i++){
        int j = i;
        int k = oo;
        while(j!=0){
            int z = j%10;
            if(z<=i)
                k = min(k,1+dp[i-z]); 
            j /= 10;
        }
        dp[i] = k;
    }
    cout << dp[x]-1 << "\n";
    return 0;

}