#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

ll n, w, res, inf = 1e18;
vector<ll>weight(101), value(101);
ll dp[100001];

void solve(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i = 0; i <= w; i++){
        dp[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = w; j >= weight[i]; j--){
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);
        }
    }

    cout << dp[w] << endl;
}

int main(){
    fastio;
    int t=1, tc=1;
    //cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
