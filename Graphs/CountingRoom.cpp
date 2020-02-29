//@author :: Abhimanyu Chauhan

// #pragma GCC target("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


#define oo			INT_MAX/2
#define f			first
#define sz(a)  ((int)(a).size())
#define s			second
#define present(c,x) ((c).find(x)!=(c).end())
#define all(v)		v.begin(),v.end()
#define pii 			pair<int,int>
#define pil 		pair<int,long long>
#define pll 		pair<long long , long long>
#define vpii 		vector<pii>
#define vpil 		vector<pil>
#define vpll 		vector<pll>
#define eb			emplace_back
#define mem(x) 			memset(x , 0 , sizeof(x))
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>
#define vll			vector<ll>
#define deb(x)		cout << #x << " " << x << endl

using namespace std;
using ll  = long long;
using lld = long double;
using l64 = int64_t;

const ll MOD =1000000007;

const int N = 1000 + 1;
string ar[N];
bool vis[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n, m;

void dfs(int i , int j){
    vis[i][j] = true;

    fo(d , 4){
        int x = i + dx[d];
        int y = j + dy[d];
        if(x >= 0 && y >= 0 && x < n && y < m && ar[x][y]=='.' && !vis[x][y]){
            dfs(x, y);
        }
    }
}

signed main(){
    mem(vis);
#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    // ios_base::sync_with_stdio(0);cin.tie(0);

    // int n , m;
    cin >> n >> m;

    fo(i , n){
        cin >> ar[i];
    }

    int cnt = 0;
    
    fo(i , n){
        fo(j , m){
            if(ar[i][j] == '.' && !vis[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << "\n";

    return 0;

}