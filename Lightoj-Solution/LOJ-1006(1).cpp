#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e4 + 5;
int a, b, c, d, e, f;
int dp[N];
int mod = 1e7+7;

int dpkoro(int n){
    if(n == 0) return a % mod;
    if(n == 1) return b % mod;
    if(n == 2) return c % mod;
    if(n == 3) return d % mod;
    if(n == 4) return e % mod;
    if(n == 5) return f % mod;
    if(dp[n] != -1) return dp[n];

    return dp[n] = (dpkoro(n-1) + dpkoro(n-2) + dpkoro(n-3) + dpkoro(n-4) + dpkoro(n-5) + dpkoro(n-6)) % mod;
}

void solve(){
    int n;
    memset(dp, -1, sizeof(dp));
    cin >> a >> b >> c >> d >> e >> f >> n;
    cout << dpkoro(n) << endl;
}

int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
