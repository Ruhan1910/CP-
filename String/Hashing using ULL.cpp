//This code can give some wa in corner case 
//If 5th prefix hash value is 10 after mod and
//6th prefix hash value is 5 after mod then Fhash function 
//will return a negative value for that in some case
//it will give wrong answer

#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

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

int main(){
    B[0]=1;
    for(int i=1; i<N; i++) B[i]=B[i-1]*bs;

    cin>>s;
    int sz=s.size();

    FH[0]=0;
    for(int i=1; i<=sz; i++) FH[i]=FH[i-1]*bs+s[i-1];

    RH[sz+1]=0;
    for(int i=sz; i>=1; i--) RH[i]=RH[i+1]*bs+s[i-1];

}
