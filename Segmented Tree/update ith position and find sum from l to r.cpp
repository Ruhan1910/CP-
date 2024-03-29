#include<bits/stdc++.h>
using namespace std;
const int SZ=100001;
int arr[SZ],tree[SZ*3];

void init(int node, int lo, int hi){
    if(lo==hi){
        tree[node]=arr[lo];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(lo+hi)/2;
    init(left,lo,mid);
    init(right,mid+1,hi);

    tree[node]=tree[left]+tree[right]; //change this
    return;
}

void update(int node, int lo, int hi, int pos, int newvalue){
    if(lo > pos || hi < pos) return;
    if(lo >= pos && hi <= pos){
        tree[node]=newvalue;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(lo+hi)/2;
    update(left,lo,mid,pos,newvalue);
    update(right,mid+1,hi,pos,newvalue);

    tree[node]=tree[left]+tree[right]; // change this
    return;
}

int query(int node, int lo, int hi, int i, int j){
    if(lo > j || hi < i) return 0; // return appropriate value
    if(lo>=i && hi <= j) return tree[node];

    int left=node*2;
    int right=node*2+1;
    int mid=(lo+hi)/2;
    int res1=query(left,lo,mid,i,j);
    int res2=query(right,mid+1,hi,i,j);

    return res1+res2; // change this
}

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1,1,n); // building the tree

    int pos,val; cin>>pos>>val;
    update(1,1,n,pos,val); // update a single index
    int l,r; cin>>l>>r;
    cout<<"Sum from "<<l<<" to "<<r<<" is: "<<query(1,1,n,l,r)<<endl; // print the sum of a given range


    return 0;
}
