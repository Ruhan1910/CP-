#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

const int N = 1e6 + 5;
double logb10[N];

void precal(){
    for(int i = 1; i < N; i++){
        logb10[i] = log10(i) + logb10[i - 1];
    }
}

void solve(){
    int n, b; cin >> n >> b;
    double up = logb10[n];
    double down = log10(b);
    int res = (up / down) + 1;

    cout << res << endl;
}

int main(){
    precal();
    fastio;
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
