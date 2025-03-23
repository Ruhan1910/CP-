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

const int N = 20;
vector<vector<int>>v(N, vector<int>(N));
int dp[N][(1 << 17)];
int n;

int dpkoro(int ind, int mask){
    if(ind == n) return 0;
    if(dp[ind][mask] != -1) return dp[ind][mask];

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(check(mask, i)) continue;

        ret = max(ret, v[ind][i] + dpkoro(ind + 1, set(mask, i)));
    }

    return dp[ind][mask] = ret;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    int res = dpkoro(0, 0);
    cout << res << endl;
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
