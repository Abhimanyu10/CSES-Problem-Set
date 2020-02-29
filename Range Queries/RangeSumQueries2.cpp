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
#define int ll
using namespace std;
using ll  = long long;
using lld = long double;
using l64 = int64_t;

const ll MOD =1000000007;

const int N = 2e5 + 10;
int ar[N] , tree[N << 2];

void upd(int l , int r , int t , int ind){
    if(l == r){
        tree[t] = ar[l];
        return;
    }

    int mid = (l + r) >> 1;
    if(ind <= mid)
        upd(l, mid, t << 1, ind);
    else
        upd(mid + 1, r, t << 1 | 1, ind);
    tree[t] = tree[t << 1] + tree[t << 1 | 1];
}

int qry(int l , int r , int t, int ql , int qr){
    if(l > qr || r < ql)
        return 0;
    if(l >= ql && r <= qr)
        return tree[t];
    int mid = (l + r) >> 1;
    return (qry(l ,mid , t << 1 , ql , qr) + qry(mid + 1 ,r , t << 1 | 1 , ql , qr));
}

signed main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , q;
    cin >> n >> q;
    fo(i, n) cin >> ar[i], upd(0, n - 1, 1, i);
    while(q--){
        int t , x , y;
        cin >> t >> x >> y;
        if(t == 2)
        cout << qry(0, n - 1, 1, x - 1, y - 1) << "\n";
        else{
            ar[x - 1] = y;
            upd(0, n - 1, 1, x - 1);
        }
    }
    return 0;

}