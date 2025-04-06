#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

const int N = 1e3 + 5;
int n;
vector<int>v(N);
int dp[N][2];

void solve(){
    cin >> n;
    for(int i = 2; i <= n+1; i++){
        cin >> v[i];
    }

    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
    for(int i = 2; i <= n + 1; i++){
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];

        if(i != 2) dp[i][0] = max(dp[i][0], v[i] + dp[i - 2][0]);
        if(i != n + 1) dp[i][1] = max(dp[i][1], v[i] + dp[i - 2][1]);
    }

    cout << max(dp[n + 1][0], dp[n + 1][1]) << endl;
}

int main(){
    fastio;
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
