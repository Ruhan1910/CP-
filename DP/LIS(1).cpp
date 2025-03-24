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

const int N = 1e5 + 5;
vector<int>v(N);
int n, dp[N];

int dpkoro(int ind){
    if(ind == n) return 0;
    if(dp[ind] != -1) return dp[ind];

    int ret = 0;
    for(int i = ind + 1; i < n; i++){
        if(v[i] > v[ind]){
            ret = max(ret, dpkoro(i));
        }
    }

    return dp[ind] = ret + 1;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, dpkoro(i));
    }

    cout << res << endl;
}

int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
