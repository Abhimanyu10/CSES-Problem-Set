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
    int ar[n];
    for(int i=0;i<n;i++) cin >> ar[i];
    unordered_set<int> hs;
    int i = 0;
    deque<int> dq;
    int ans = 0;
    while(i<n){
        while(i<n && hs.find(ar[i])==hs.end()){
            hs.insert(ar[i]);
            dq.push_back(ar[i]);
            i++;
        }
        ans = max(ans,(int)hs.size());
        while(i<n && dq.front()!=ar[i]){
            hs.erase(dq.front());
            dq.pop_front();
        }
        if(i<n && dq.front()==ar[i]){
            hs.erase(dq.front());
            dq.pop_front();
        }
    }

    cout << ans ;

    return 0;

}