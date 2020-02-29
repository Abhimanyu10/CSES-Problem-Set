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

const int N = 502;
vector<vector<int>> dp(N,vector<int>(N,oo));

int f(int a,int b){
    if(a==b) return 0;
    auto &res = dp[a][b];

    if(res!=oo) return res; 
    
    for(int i = 1;i<a;i++)
        res = min(res,1+f(a-i,b)+f(i,b));
    
    for(int i = 1;i<b;i++)
        res = min(res,1+f(a,b-i)+f(a,i));
    
    return res;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int a,b;
    cin >> a >> b;

    cout << f(a,b) << "\n";

    return 0;

}