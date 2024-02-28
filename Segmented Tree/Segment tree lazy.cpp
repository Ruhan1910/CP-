#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
vector<ll>arr;
struct Node{
    ll sum, prop;
} tree[4*N];

void build(ll node, ll lo, ll hi){
    if(lo == hi){
        tree[node].sum = arr[lo];
        return;
    }
    ll mid = (lo + hi) / 2;
    ll left = node*2, right = node*2+1;

    build(left, lo, mid);
    build(right, mid+1, hi);

    tree[node].sum = tree[left].sum + tree[right].sum; // change here
    tree[node].prop = 0; // change here
}

void updateRange(ll node, ll lo, ll hi, ll l, ll r, ll val){
    if(lo>r || hi<l) return;
    if(lo>=l && hi<=r){
        tree[node].sum += ((hi-lo+1) * val); // change here
        tree[node].prop += val; // change here
        return;
    }

    ll mid = (lo+hi) / 2;
    ll left = node*2, right = node*2+1;

    updateRange(left, lo, mid, l, r, val);
    updateRange(right, mid+1, hi, l, r, val);

    tree[node].sum = tree[left].sum + tree[right].sum + ((r-l+1) * tree[node].prop);

}

ll query(ll node, ll lo, ll hi, ll l, ll r, ll carry){
    if(lo>r || hi<l) return 0; // change here
    if(lo>=l && hi<=r){
        return tree[node].sum + (carry * (hi-lo+1));
    }
    ll mid = (lo+hi) / 2;
    ll left = node*2, right = node*2+1;

    ll x = query(left, lo, mid, l, r, carry+tree[node].prop);
    ll y = query(right, mid+1, hi, l, r, carry+tree[node].prop);

    return x+y;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, q; cin>>n>>q;
    arr.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    build(1, 1, n);

    while(q--){
        int op; cin>>op;
        if(op){
            int l, r, val; cin>>l>>r>>val;
            updateRange(1, 1, n, l, r, val);
        }
        else{
            int l, r; cin>>l>>r;
            ll res = query(1, 1, n, l, r, 0);
            cout<<res<<endl;
        }
    }
}
