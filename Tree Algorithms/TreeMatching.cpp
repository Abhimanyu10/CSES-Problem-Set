#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD 1000000007
#define f first
#define s second
#define all(v) v.begin(),v.end()

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

const int N = 2*(1e5+1);
vector<bool> vis(N,false);


int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    while(n--!=1){
        int u,v;
        cin >> u >> v;
        if(!vis[u] and !vis[v]){
            cnt++;
            vis[u] = true;
            vis[v] = true;
        }
    }
    cout << cnt << "\n";
    return 0;

}