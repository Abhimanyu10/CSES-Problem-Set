#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define oo          INT_MAX/2
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

const int N = 1000;
char ar[N][N];
int dp[N][N];

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    string s;
    for(int i =0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++) {
            ar[i][j] = s[j];
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ar[i][j] == '.'){
                if(i>0 && j>0)
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
                else if(i>0)
                dp[i][j] = dp[i-1][j];
                else if(j>0)
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    cout << dp[n-1][n-1]%MOD << "\n";

    return 0;

}