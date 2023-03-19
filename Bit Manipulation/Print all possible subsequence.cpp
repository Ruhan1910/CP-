#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PI acos(-1.0)
const ll MOD = 1e9+7;


void solve(){
    int sz; cin>>sz; //size should be little because we will run a loop until 2^size;
    int arr[sz];
    for(int i=0; i<sz; i++) cin>>arr[i];
    for(int i=1; i<(1<<sz); i++){
        for(int j=sz-1; j>=0; j--){
            if(i&(1<<j)) cout<<arr[(sz-1)-j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------------"<<endl;
    for(int i=1; i<(1<<sz); i++){
        for(int j=0; j<sz; j++){
            if(i&(1<<j)) cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1,tc=1;
    //cin>>t;
    while(t--){
        //cout<<"Case "<<tc++<<": ";
        solve();
    }

    return 0;
}
