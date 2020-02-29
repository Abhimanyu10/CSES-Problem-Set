// https://cses.fi/problemset/task/1070

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

    int n;
    cin >> n;

    if(n==2 || n==3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    vector<int> ans;

    for(int i=2;i<=n;i+=2) ans.push_back(i);
    for(int i=1;i<=n;i+=2) ans.push_back(i);
    
    for(auto i : ans) cout << i << " "; 

    return 0;
}