//Using Digit Dp
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
int mp[N];
int dp[N][N][N];
vector<int>temp;

int dpkoro(int x, int prv, int flag){
    if(x == 0) return 1;
    if(dp[x][prv][flag] != -1) return dp[x][prv][flag];


    int ret = 0;
    for(int i = 0; i < 10; i++){
        if(!mp[i]) continue;
        if(!flag){
            ret += dpkoro(x - 1, i, 1);
        }
        else{
            if(abs(i - prv) <= 2){
                ret += dpkoro(x - 1, i, flag);
            }
        }
    }

    return dp[x][prv][flag] = ret;
}

void solve(){
    cin >> n >> k;
    memset(mp, 0, sizeof(mp));
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x] = 1;
    }

    memset(dp, -1, sizeof(dp));
    int res = dpkoro(k, 0, 0);

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
