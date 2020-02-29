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

const int N = 8;
int dx[] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
int dy[] = {  1, 2,  2,  1, -1, -2, -2, -1 };
int dis[N][N];

bool check(){
    bool ok = false;
    fo(i, N) fo(j, N) ok |= (dis[i][j] == -1);
    return !ok;
}


bool dfs(int x , int y , int t ){
    // if(check())
    //     return true;
    if(t == 64)
        return true;
    deb(t);
    fo(i , 8){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X > -1 && Y > -1 && X < N && Y < N && dis[X][Y]==-1){
            dis[X][Y] = t;
            if(dfs(X, Y, t + 1))
                return true;
            dis[X][Y] = -1;
        }
    }
    return false;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif
    memset(dis , - 1 , sizeof(dis));
    ios_base::sync_with_stdio(0);cin.tie(0);

    int x , y;
    cin >> x >> y;
    swap(x, y);
    x--;
    y--;

    dis[x][y] = 1;
    dfs(x, y, 2);

    fo(i , 8){
        fo(j, 8)
            cout << dis[i][j] << " ";
        cout << "\n";
    }

    return 0;

}