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

int dpkoro(int i, int f){
    if(i >= n + 1) return 0;
    if(dp[i][f] != -1) return dp[i][f];
    if(f && i == n) return 0;

    int ret = dpkoro(i + 1, f);
    ret = max(ret, v[i] + dpkoro(i + 2, max(f, (i == 1) ? 1 : 0)));

    return dp[i][f] = ret;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dpkoro(1, 0) << endl;
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
