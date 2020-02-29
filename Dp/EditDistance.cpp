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

string a,b;
vector<vector<int>> dp(5002,vector<int>(5002,0));

int fun(int i,int j){
    if(i>=(int)a.size() && j>=(int)b.size()) return 0;
    if(i>=(int)a.size())
        return dp[i][j] = 1+fun(i,j+1);
    
    if(j>=(int)b.size())
        return dp[i][j] = 1+fun(i+1,j);
    
    int &res = dp[i][j];
    if(res!=0) return dp[i][j];
    if(a[i]==b[j])
        return res = fun(i+1,j+1);
    
    return res = 1+min({fun(i+1,j+1),fun(i+1,j),fun(i,j+1)});
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> a >> b;
    cout << fun(0,0) << '\n';

    return 0;

}