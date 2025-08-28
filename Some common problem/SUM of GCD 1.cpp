//Sum of GCD from (1, N) + (2, N) + ........ + (N - 1, N)

#include<bits/stdc++.h>
using namespace std;
#define endl '\n' //change during interactive problems
#define ll long long
#define check(n , k) (n & (1LL << k))
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define toggle(n, k) (n ^ (1 << k));
#define count_on_bit(n) __builtin_popcount(n);
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

//Try to look at it from a whole new angle
//Why your way of thinking was not correct and what did you miss?
//What did you learn from this problem?
//Main goal is to learn new stuff

const int N = 1e6 + 10;
vector<ll> phi(N);

void totient(){
    for(int i = 0; i < N; i++){
        phi[i] = i;
    }

    for(int i = 2; i < N; i++){
        if(phi[i] == i){
            for(int j = i; j < N; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
}

vector<ll> v(N);
void precal(){
    for(int i = 1; i < N; i++){
        for(int j = i + i; j < N; j += i){
            v[j] += (ll)i * phi[j / i];
        }
    }
}

void solve(){
    ll n; 
    while(cin >> n){
        if(n == 0) break;
        cout << v[n] << endl;
    }
}

int main(){
    totient();
    precal();
    fastio;
    int t=1, tc=1;
    //cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
