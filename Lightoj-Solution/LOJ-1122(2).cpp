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

const int N = 15;
int n, k;
vector<int>v(N);
int dp[N][N];
vector<int>temp;

int dpkoro(int x, int prv){
    if(x == 0) return 1;
    if(dp[x][prv] != -1) return dp[x][prv];

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(prv == 0 || (abs(prv - v[i]) <= 2)){
            ret += dpkoro(x - 1, v[i]);
        }
    }

    return dp[x][prv] = ret;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    int res = dpkoro(k, 0);
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
