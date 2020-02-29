#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll psum,ssum,sum,bsum;
};

Node combine(const Node& left,const Node& right){
	Node ans;
	ans.sum = left.sum + right.sum;
	ans.psum = max({left.psum,left.sum+right.psum});
	ans.ssum = max({right.ssum,left.ssum+right.sum});
	ans.bsum = max({left.ssum+right.psum,ans.sum,ans.psum,ans.ssum,left.bsum,right.bsum});
	return ans;
}

Node generate(ll i){
	Node res{i,i,i,i};
	return res;
}
const int N = 2*(1e5)+1;
vector<Node> tree(4*N);
vector<ll> ar(N);
int n;

void build(int l,int r,int node){
	if(l==r) {tree[node] = generate(ar[l]) ;return;}
	int mid = (l+r)>>1;
	build(l,mid,2*node);
	build(mid+1,r,2*node+1);
	tree[node] = combine(tree[2*node],tree[2*node+1]);
	return;
}

Node qry(int l,int r,int node,int ql,int qr){
	if(r<ql || l>qr) return Node{0,0,0,0};	
	if(l>=ql && r<=qr) return tree[node];
	int mid = (l+r)>>1;
	if(mid<ql) return qry(mid+1,r,2*node+1,ql,qr);
	if(mid>=qr) return qry(l,mid,2*node,ql,qr);
	Node left = qry(l,mid,2*node,ql,qr);
	Node right = qry(mid+1,r,2*node+1,ql,qr);
	return combine(left,right);	
}

void upd(int l,int r,int node,int index,ll val){
    if(l==r){
        ar[l] = val;
        tree[node] = generate(ar[l]);
        return;
    }

    int mid = (l+r)>>1;

    if(mid>=index){
        upd(l,mid,2*node,index,val);
    }else{
        upd(mid+1,r,2*node+1,index,val);
    }

    tree[node] = combine(tree[2*node],tree[2*node+1]);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
    cin >> n;
	for(int i=0;i<n;i++) cin >> ar[i];
    cin >> q;
	build(0,n-1,1);
	int a,b;
	while(q--){
        int t;
        cin >> t;
        cin >> a >> b;
        if(t==0){
            upd(0,n-1,1,a-1,b);
        }else{
		    cout << qry(0,n-1,1,a-1,b-1).bsum << "\n";
        }
    }	
	return 0;
}
