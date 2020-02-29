// https://cses.fi/problemset/task/1645
//@author :: Abhimanyu Chauhan

#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define oo			INT_MAX/2
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)		for(int i=k;i<n;i++)
#define deb(x)			cout << #x << " " << x << endl

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

template<typename T>
istream& operator >> (istream& in , vector<T> &ar){
    for (int i = 0 ; i < (int) ar.size() ; i++) in >> ar[i];
return in;
}

template<typename T>
ostream& operator << (ostream& out , vector<T> &ar){
    for (int i = 0 ; i < (int) ar.size() ; i++) out << ar[i];
return out;
}

const int N = 2e5+10;
vector<int> ar(N , 0) , ans(N , 0) , tree(4*N , 0);
int n;

int qry(int ql ,int qr , int val ,int l = 0 ,int r = n-1 ,int t = 1){
    if(l==r){
        return l;
    }
    if(l > qr || r < qr) return -1;
    
}

void upd(int ind , int val , int l = 0 , int r = n-1 , int t = 1){
    if(l==r){
        ar[ind] = val;
        tree[t] = ar[ind];
        return ;
    }

    int mid = (l+r)>>1;
    if(ind > mid){
        upd(ind , val , mid+1 , r , 2*t+1);
    }else{
        upd(ind , val , l , mid , 2*t);
    }
    tree[t] = min(tree[2*t] , tree[2*t+1]);
    return ;
}

int main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    fo(i , n) cin >> ar[i];
    
    ans[0] = 0;
    Fo(i , 1 , n){
        qry(0,i-1);
    }

    return 0;

}
