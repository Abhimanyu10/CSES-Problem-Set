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

int main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , m , k;
    cin >> n >> m >> k;
    vector<int> ar(N , 0) , p(N , 0);
    fo(i , n){
        cin >> ar[i];
    }

    fo(i , m){
        cin >> p[i];
    }

    sort(ar.begin() , ar.begin() + n);
    sort(p.begin() , p.begin() + m);

    int i = 0 , j = 0 , cnt = 0;
    while(j<m && i<n){
        if(p[j]-ar[i] <=k and p[j]-ar[i] >= -k){
            i++;j++;
            cnt++;
        }else if(p[j]-ar[i] > k){
            i++;
        }else {
            j++;
        }
    }
    
    cout << cnt << "\n";

    return 0;

}