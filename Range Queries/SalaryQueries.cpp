#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD 1000000007
#define f first
#define s second
#define all(v) v.begin(),v.end()

using namespace std;
using ll  = long long;\
using lld = long double;
using vll = int64_t;

const int N = 2*(1e5+1);
vector<int> ar(N,0);
int n,m;


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    ordered_set os;
    for(int i=0;i<n;i++) {
        cin >> ar[i];
        os.insert(ar[i]);
    }
    while(m--){
        string s;
        cin >> s;
        if(s=="?"){
            int u,v;
            cin >> u >> v;
            cout << (os.order_of_key(v+1) - os.order_of_key(u)) << '\n';
        }else{
            int u;
            cin >> u;
            int x;
            cin >> x;
			os.erase(os.find_by_order(os.order_of_key(ar[u-1])));
            ar[u-1] = x;
            os.insert(ar[u-1]);
        }
    }


    return 0;

}