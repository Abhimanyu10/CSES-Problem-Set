// #pragma GCC target("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>
#define mp          make_pair
#define int ll
using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;


const int N = 2*(1e5+1);
vector<int> tree(4*N,0);
vector<int> ar(N,0);

void build(int l,int r,int t){
    if(l==r){
        tree[t] = ar[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,2*t);
    build(mid+1,r,2*t+1);
    tree[t] = max(tree[2*t],tree[2*t+1]);
    return;
}


int qry(int l,int r,int t,int q){
    if(l==r){
        int tmp = ar[l];
        if(ar[l] - q >= 0){
            ar[l]  = ar[l]-q;
            tree[t] = ar[l];
            return l+1;
        }else
            return 0;
    }   

    int mid = (l+r)>>1;
    int ans;
    
    if(tree[2*t]>=q){
        ans = qry(l,mid,2*t,q); 
    }
    else if(tree[2*t+1]>=q){
        ans = qry(mid+1,r,2*t+1,q);
    }else{
        ans = 0;
    }

    tree[t] = max(tree[2*t],tree[2*t+1]);
    return ans;
}


signed main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("in.txt", "r", stdin);
    int n,q;
    cin >> n >> q;
    
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }

    build(0,n-1,1);

    for(int i=0;i<q;i++){
        int q;
        cin >> q;
        cout << qry(0,n-1,1,q) << " ";
    }
    
    return 0;
}