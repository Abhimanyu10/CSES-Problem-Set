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

    int n, k;
    cin >> n >> k;
    
    int ar[n];
    multiset<int> hs; hs.clear();
    for(auto &i : ar) {
        cin >> i;
        hs.insert(i);
    }
    
    while(k--){
        int tmp; cin >> tmp;
        auto it = hs.upper_bound(tmp);

        if(it!=hs.begin()){
            cout << *(--it) << "\n" ;
            hs.erase(it);
        }else{
            cout << "-1\n";
        }

    }

    return 0;
}