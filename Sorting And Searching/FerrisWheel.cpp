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

#define int ll

int32_t main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,k;
    cin >> n >> k;
    int ar[n];
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }

    sort(ar,ar+n);

    int i = 0, j = n-1;
    int ans = 0;
    while(i<j){
        if(ar[j]+ar[i]<=k){
            j--;i++;
            ans++;
        }else{
            j--;
            ans++;
        }
    }
    if(i==j) ans+=1;
    cout << ans << "\n";

    return 0;

}