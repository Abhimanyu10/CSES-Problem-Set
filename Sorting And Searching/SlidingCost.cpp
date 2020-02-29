

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag ,tree_order_statistics_node_update>

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,k;    
    cin >> n >> k;
    ll ar[n];

    ordered_set hs;

    ll sum = 0;

    for(int i=0;i<n;i++) {
        cin >> ar[i];
    }

    int i =0;

    while(i<k){ 
        sum += ar[i];
        hs.insert(ar[i++]);
    }
    auto j = hs.find_by_order((k-1)/2);
    
    cout << sum-k*(*j) << " ";

    while(i<n){
        hs.erase(hs.find_by_order(hs.order_of_key(ar[i-k])));
        sum-=ar[i-k];
        sum+=ar[i];
        hs.insert(ar[i++]);
        j = hs.find_by_order((k-1)/2);
        if(k%2==0)
        cout << min(sum-k*(*j),sum-k*(*prev(j))) << " ";
        else
        cout << sum-k*(*j) << " ";
    }    

    return 0;
}
