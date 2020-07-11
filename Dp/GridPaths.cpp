
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

const int N = 1010;
string ar[N];
ll dp[N][N];

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> ar[i];
    
    dp[0][0] = 1;

    auto relax = [](ll & a , ll b){
        a = (a % MOD + b % MOD) % MOD;
    };

    //forward style dp :: 
    //you know the answer for a state dp[i][j] , using this you
    //fill the other states

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            if(ar[i][j] == '.'){
                relax(dp[i + 1][j] , dp[i][j]);
                relax(dp[i][j + 1] , dp[i][j]);
            }
    if(ar[n - 1][n - 1] != '.')
        dp[n - 1][n - 1] = 0;
    cout << dp[n - 1][n - 1] << "\n";

    return 0;

}
