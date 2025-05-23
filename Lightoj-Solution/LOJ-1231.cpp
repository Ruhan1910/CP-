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

const int N = 1005;
vector<int>a(N), b(N);
int n, k;
int dp[N][N];
int mod = 1e8 + 7;

int dpkoro(int ind, int x){
    if(ind == n){
        if(x == k) return 1;
        return 0;
    }
    //These two base cases will speed up the code. If we don't want to use them we will need to declare
    //the size of dp as dp[50][100000] (100 * 20 * 50 = 10000). In that case, we will get TLE because
    //there are 100 tc so total Time complexity = 1e5 * 50 * 100 = 5e8
    //If we use this two line then x will never cross 1000 so dp[50][1000] will be perfectly work
    if(x == k) return 1;
    if(x > k) return 0;

    if(dp[ind][x] != -1) return dp[ind][x];

    int ret = 0;
    for(int i = 0; i <= b[ind]; i++){
        ret += dpkoro(ind + 1, x + (i * a[ind]));
        ret %= mod;
    }

    return dp[ind][x] = ret;
}

void solve(){
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

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
