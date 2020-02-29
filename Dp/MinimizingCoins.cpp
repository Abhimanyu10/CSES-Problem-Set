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
vector<vector<int>> dp(N,vector<int>(1000000+1,INT_MAX/100)); 
int n;
int fun(int i,int x){
    if(x==0) return 0;
    if(i>=n) return INT_MAX/100;
 
    int &res = dp[i][x];
 
    if(res!=0) return res; 
 
    if(ar[i]<=x)
        return res = min(fun(i,x-ar[i])+1,fun(i+1,x));
    else
        return INT_MAX/100;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int x;
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
    }

    sort(ar,ar+n);
    
    // auto z = fun(0,x);
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j==0) {dp[i][j] =  0 ; continue;}
            if(ar[i]<=j){
                dp[i][j] = min(1+dp[i][j-ar[i]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=x;j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout <<( dp[n][x]==INT_MAX/100 ? -1 : dp[n][x] )<< "\n";
    
    return 0;
}