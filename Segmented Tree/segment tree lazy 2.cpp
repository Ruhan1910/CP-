#include<bits/stdc++.h>
using namespace std;
#define ll long long

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e5+10;
ll tree[4*N], lazy[4*N];
vector<ll>arr;

void relax(int node, int l, int r){
    tree[node] += (r-l+1)*lazy[node];
    if(l!=r){
        int left = node*2, right = node*2+1;
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
    }
    lazy[node] = 0;
}

void updateMerge(int node, int left, int right){
    tree[node] = tree[left] + tree[right];
}

ll queryMerge(ll x, ll y){
    return x+y;
}

void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node] = arr[lo];
        return;
    }

    int mid = (lo+hi)/2;
    int left = node*2, right = node*2+1;

    build(left, lo, mid);
    build(right, mid+1, hi);
    updateMerge(node, left, right);
    lazy[node] = 0;
}

void updateRange(int node, int lo, int hi, int l, int r, ll val){
    if(lazy[node]) relax(node, lo, hi);
    if(lo > r || hi < l) return;
    if(lo >= l && hi <= r){
        lazy[node] += val;
        relax(node, lo, hi);
        return;
    }

    int mid = (lo+hi)/2;
    int left = node*2, right = node*2+1;
    updateRange(left, lo, mid, l, r, val);
    updateRange(right, mid+1, hi, l, r, val);

    updateMerge(node, left, right);
}

ll query(int node, int lo, int hi, int l, int r){
    if(lazy[node]) relax(node, lo, hi);
    if(lo > r || hi < l) return 0;
    if(lo >= l && hi <= r) return tree[node];

    int mid = (lo+hi)/2;
    int left = node*2, right = node*2+1;
    ll x = query(left, lo, mid, l, r);
    ll y = query(right, mid+1, hi, l, r);

    return queryMerge(x, y);
}

void solve(){
    int n, q; cin>>n>>q;
    arr.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    build(1, 1, n);

    while(q--){
        int op; cin>>op;
        if(op == 1){
            int l, r;
            ll val;
            cin>>l>>r>>val;
            updateRange(1, 1, n, l, r, val);
        }
        else{
            int l, r; cin>>l>>r;
            ll res = query(1, 1, n, l, r);
            cout<<res<<endl;
        }
    }
}

int main(){
    iofile();
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}
