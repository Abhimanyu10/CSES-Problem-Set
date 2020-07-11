#include<bits/stdc++.h>

#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;
#define int ll
const int N = 1e5 + 100;
const int M = 105;
int ar[N] , dp[N][M];

signed main(){

#ifndef ONLINE_JUDGE
//	freopen("in.txt" , "r" , stdin);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) cin >> ar[i];
    for(int j = 1 ; j <= m ; j++)
        dp[0][j] = 1;

    auto relax = [](int & a , int b){
        a = (a % MOD + b % MOD) % MOD;
    };

    for(int i = 0 ; i < n ; i++){
        if(ar[i] == 0){
            for(int j = 1 ; j <= m ; j++){
                relax(dp[i + 1][j] , dp[i][j]);
                if(j > 1)
                    relax(dp[i + 1][j - 1] , dp[i][j]);
                if(j < m)
                    relax(dp[i + 1][j + 1] , dp[i][j]);
            }
        }else{
            int j = ar[i];
            relax(dp[i + 1][j] , dp[i][j]);
            relax(dp[i + 1][j + 1] , dp[i][j]);
            relax(dp[i + 1][j - 1] , dp[i][j]);
        }
    }

//    for(int i = 0 ; i <= n ; i++){
//        for(int j = 0 ; j <= 5 ; j++)
//            cout << dp[i][j] << " " ;
//        cout << '\n';
//    }
//
    if(ar[n - 1] != 0)
        cout << dp[n - 1][ar[n - 1]] << '\n'; 
    else{
        int ans = 0;
        for(int j = 1 ; j <= m ; j++)
            relax(ans , dp[n - 1][j]);
        cout << ans << '\n';
    }
    return 0;

}

