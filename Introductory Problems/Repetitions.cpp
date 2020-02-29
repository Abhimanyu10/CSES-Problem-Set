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

    string s;
    cin >> s;
    int dp[s.size()]; fill(dp,dp+s.size(),0);
    
    dp[0] = 1;
    
    for(int i=1;i<s.size();i++)
        if(s[i]==s[i-1]) dp[i] = dp[i-1]+1;
        else dp[i] = 1;
    
    cout << *max_element(dp,dp+s.size());
    
    return 0;

}