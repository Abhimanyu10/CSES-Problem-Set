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

const int N = 1001;
string ar[N];

struct node{
    int i, j;
    string x;
    node(){}
    node(int ii, int jj, string ss = "") { i = ii, j = jj, x = ss; };
};

bool vis[N][N];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
char dir[4] = {'L', 'U', 'D', 'R'};
string ans="";
pii par[N][N];
signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m;
    cin >> n >> m;

    queue<node> q;
    pii en;

    fo(i , n){
        cin >> ar[i];
        fo(j, m) if (ar[i][j] == 'A') vis[i][j] = true , par[i][j] = {i , j} , q.push(node(i, j));
        else if (ar[i][j] == 'B') en = {i, j};
    }

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        vis[p.i][p.j] = true;
        // string tmp;
        if(p.i == en.f && p.j == en.s) {
            // ans = p.x;
            break;
        }
        // tmp = p.x;
        fo(i , 4){
            int x = p.i + dx[i];
            int y = p.j + dy[i];
            // tmp.pb(dir[i]);
            if(x < n && y < m && x >=0 && y >=0 && !vis[x][y] && (ar[x][y] == '.' || ar[x][y] == 'B'))
                vis[x][y] = true , par[x][y] = {p.i , p.j},q.push(node(x, y));
            // tmp.pop_back();
        }
    }
    int i = en.f, j = en.s;

    while(true){
        if(!vis[i][j])
            break;
        if(par[i][j] == make_pair(i , j))
            break;
        fo(o , 4) {
            int x = i + dx[o];
            int y = j + dy[o];
            if(par[i][j]==make_pair(x , y)){
                i = x;
                j = y;
                ans.push_back(dir[o]);
                break;
            }
        }
    }
    reverse(all(ans));

    if(vis[en.f][en.s]){
        cout << "YES\n"
             << ans.size() << "\n"
             << ans << '\n';
    }else{
        cout << "NO\n";
    }

    return 0;
}