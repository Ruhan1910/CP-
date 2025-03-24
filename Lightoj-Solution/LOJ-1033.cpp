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
string s;
int n;
int dp[N][N];

int dpkoro(int lo, int hi){
    if(lo >= hi) return 0;
    if(dp[lo][hi] != -1) return dp[lo][hi];

    int ret = 0;
    if(s[lo] == s[hi]){
        ret = dpkoro(lo + 1, hi -1);
    }
    else{
        ret = 1 + min(dpkoro(lo + 1, hi), dpkoro(lo, hi - 1));
    }

    return dp[lo][hi] = ret;
}

void solve(){
    cin >> s;
    n = s.size();

    memset(dp, -1, sizeof(dp));
    int res = dpkoro(0, n-1);
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
