// https://cses.fi/problemset/task/1640
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

const int N = 2e5+1;
vector<int> ar(N , 0);

int main(){

#ifndef ONLINE_JUDGE 
    // freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n , x;
    cin >> n >> x;
    set<int> hs;
    fo(i , n) {
        cin >> ar[i] ;
        if(hs.find(ar[i])!=hs.end()) {
            for(int j = 0; j <= i;j++) 
                if(ar[j]==(x-ar[i]))
                cout << i+1 << " " << j+1 << "\n"; return 0;
        }else{
            hs.insert(x-ar[i]);
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;

}