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
vector<int> ar(N,0);

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }

    unordered_map<int,int> hm;
    hm.reserve(1024);
    hm.max_load_factor(0.25);
    
    for(int i=0;i<n;i++){
        for(int j = 1;j*j<=ar[i];j++){
            if(ar[i]%j!=0) continue;
            if(j*j!=ar[i])
            {
                hm[j]++;
                hm[ar[i]/j]++;
            }else{
                hm[j]++;
            }
        }
    }

    int ans = 1;
    for(auto j: hm){
        if(j.second>=2){
            ans = max(ans,j.first);
        }
    }

    cout << ans << "\n";

    return 0;

}