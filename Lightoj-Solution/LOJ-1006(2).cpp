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

void solve(){
    int n;
    for(int i = 0; i < 6; i++){
        cin >> dp[i];
        dp[i] %= mod;
    }
    cin >> n;

    for(int i = 6; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= 6; j++){
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }

    cout << dp[n] << endl;
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
