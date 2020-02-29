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
    ll s = (ll)n*((ll)n+1LL)/2;
    if(s%2==1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        s/=2;
        unordered_set<int> hs,hs1;
        hs.max_load_factor(0.25); hs.reserve(1024);
        for(int i = n ; i >= 1 ; i--){
            if(i<=s) {
                hs.insert(i);
                s-=i;
            }else{
                hs1.insert(i);
            }
        }
        cout << hs.size() << "\n";
        for(const int &i : hs){
            cout << i << " ";
        }
        cout << "\n";
        cout << hs1.size() << "\n";
        for(const int &i : hs1){
            cout << i << " ";
        }
    }

    return 0;

}