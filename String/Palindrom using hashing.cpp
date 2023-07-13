#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

const int N=100005;
const ull bs=3797;
string s; 
ull FH[N], RH[N], B[N];

ull Fhash(int l, int r){
    return FH[r]-(FH[l-1]*B[r-l+1]);
}

ull Rhash(int l, int r){
    return RH[l]-(RH[r+1]*B[r-l+1]);
}

bool ispal(){
    int sz=s.size();
    int x=sz/2;
    int y=(sz&1)?x+2:x+1;

    return Fhash(1, x)==Rhash(1, y);
}

void solve(){
    B[0]=1;
    for(int i=1; i<N; i++) B[i]=B[i-1]*bs;

    cin>>s;
    int sz=s.size();

    FH[0]=0;
    for(int i=1; i<=sz; i++) FH[i]=FH[i-1]*bs+s[i-1];

    RH[sz+1]=0;
    for(int i=sz; i>=1; i--) RH[i]=RH[i+1]*bs+s[i-1];

    if(ispal()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    //sieve();
    //fastio;
    iofile();
    int t=1, tc=1;
    //cin>>t;
    //cin.ignore();
    while(t--){
        //cout<<"Case "<<tc++<<": ";
        solve();
    }

    return 0;
}
