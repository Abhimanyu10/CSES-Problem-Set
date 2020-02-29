#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

const int N = 101;
vector<int> ar(N,0);

int dp[101][100001];
int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    int sum = 0;

    for(int i=1;i<=n;i++){
        cin >> ar[i];
        sum+=ar[i];
    }


    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++) dp[i][j] = 0;
    }

    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j =1 ;j<=sum;j++){
            if(j-ar[i]>=0)
            dp[i][j] = dp[i-1][j-ar[i]] + dp[i-1][j];
            else 
            dp[i][j] = dp[i-1][j];
        }
    }
    vector<int> ans;

    for(int j = 1; j <= sum ; j++)
    {
        for(int i = 0;i<=n;i++){
            if(dp[i][j]!=0){
                ans.push_back(j);
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    sort(all(ans));
    for(int i : ans) cout << i << " ";


    return 0;

}