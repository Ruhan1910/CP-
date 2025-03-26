#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 105;
vector<int>v(N);
int n, k;
int dp[10001];
int mod = 1e8 + 7;

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            //for each coin(sorted) we will find the number of way to make j(1, 2, 3...)
            //suppose for a coin 2 we will increase dp[1-k] by (ignore 1-2 because it's negative)
            //dp[2 - 2], dp[3 - 2], dp[4 - 2]..... dp[k - 2] then again for next coin
            //suppose 5 we will increase dp[1 - k] by dp[5 - 5], dp[6 - 5],....dp[k - 5]
            //that's mean for each coin we will check how many way exist that we can make
            //(1 - k) with this coin. Then add that value to dp[1 - k]. By this way for each
            //coin we update the value of minimum one so a topological order will maintain.

            if(v[i] > j) continue;
            dp[j] += dp[j - v[i]];
            dp[j] %= mod;
        }
    }

    cout << dp[k] << endl;
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
