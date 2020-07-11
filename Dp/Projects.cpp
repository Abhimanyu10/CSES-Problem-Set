#include<bits/stdc++.h>
#define int ll
#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int N = 5e5 + 10;
array<int,3> ar[N];
vpii adj[N];
vi dp(N , 0);
signed main(){

#ifndef ONLINE_JUDGE
///	freopen("in.txt" , "r" , stdin);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    vi tmp;    
    fo(i , n){
        cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
        tmp.pb(ar[i][0]);
        tmp.pb(ar[i][1]);
    }

    sort(all(tmp));
    tmp.erase(unique(all(tmp)) , tmp.end());
    
    int mx = 0;
    fo(i , n)
        fo(j , 2){
            ar[i][j] = lower_bound(all(tmp) , ar[i][j]) - tmp.begin(); 
            mx = max(mx , ar[i][j]);
        }

    fo(i , n)
        adj[ar[i][0]].emplace_back(ar[i][1] , ar[i][2]);
    
    auto relax = [](int & a , int b){
        a = max(a , b);
    };

    for(int i = 0 ; i < N - 2 ; i++){
        relax(dp[i + 1] , dp[i]);
        for(auto [j , w] : adj[i])
            relax(dp[j + 1] , w + dp[i]);
    }

    cout << *max_element(all(dp)) << '\n';

    return 0;
}

