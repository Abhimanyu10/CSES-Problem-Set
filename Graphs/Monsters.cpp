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

const int N = 1e3 + 10;
string ar[N];
int d1[N][N];
int d2[N][N];
bool vis[N][N];
pii par[N][N];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
char dir[4] = {'L', 'U', 'D', 'R'};

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);

    fo(i, N) fo(j, N) d1[i][j] = d2[i][j] = oo;
    mem(vis);

    pii st = {-1  , -1};
    int n, m;
    cin >> n >> m;
    fo(i, n) cin >> ar[i];
    fo(i, n)
        fo(j, m) 
            if (ar[i][j] == 'A'){
                st = {i, j};
                break;
            }

    queue<pii> q;
    fo(i, n)
        fo(j, m) 
            if (ar[i][j] == 'M') q.push({i, j}), vis[i][j] = true, d1[i][j] = 0;

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        fo(i , 4){
            int x = p.f + dx[i];
            int y = p.s + dy[i];
            if(x < n && y < m && x > -1 && y > -1 && !vis[x][y] && ar[x][y] != '#')
                q.push({x, y}) , vis[x][y] = true , d1[x][y] = 1 + d1[p.f][p.s];
        }
    }


    mem(vis);
    fo(i , n)
        fo(j, m) 
            if (ar[i][j] == 'A') 
                q.push({i, j}) , vis[i][j] = true , d2[i][j] = 0;
    

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        fo(i , 4){
            int x = p.f + dx[i];
            int y = p.s + dy[i];
            if(x < n && y < m && x > -1 && y > -1 && !vis[x][y] && ar[x][y] != '#')
                q.push({x, y}) , vis[x][y] = true , d2[x][y] = 1 + d2[p.f][p.s] , 
                        par[x][y] = {p.f , p.s};
        }
    }

    pii des = { -1 , -1 };
    fo(i , n) {
        if(ar[i][0] == '.'){
            if(d2[i][0] < d1[i][0]){
                des = {i, 0};
                break;
            }
        }
        if(ar[i][m - 1] == '.'){
            if(d2[i][m - 1] < d1[i][m - 1]){
                des = {i, m - 1};
                break;
            }
        }
        if(ar[i][0] == 'A' || ar[i][m - 1] == 'A'){
            cout << "YES\n";
            cout << "0\n";
            return 0;
        }
    }

    fo(i , m){
        if(ar[0][i] == '.'){
            if(d2[0][i] < d1[0][i]){
                des = {0, i};
                break;
            }
        }
        if(ar[n - 1][i] == '.'){
            if(d2[n - 1][i] < d1[n - 1][i]){
                des = {n - 1, i};
                break;
            }
        }
        
        if(ar[0][i] == 'A' || ar[n - 1][i] == 'A'){
            cout << "YES\n";
            cout << "0\n";
            return 0;
        }    
    }

    
    //constructing the path;

    if(des == make_pair(-1 , -1) || st == make_pair(-1 , -1)){
        cout << "NO\n";
        return 0;
    }

    string ans;
    int i = des.f, j = des.s;
    while(true){
        if(make_pair(i , j) == st) 
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

    cout << "YES\n"
             << ans.size() << "\n"
             << ans << '\n';

    return 0;

}