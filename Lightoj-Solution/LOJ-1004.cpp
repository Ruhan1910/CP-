#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e2 + 5;
vector<int>v[2*N];
int n, dp[2*N][N];

int dpkoro(int ith, int i){
    if(ith == 2 * n - 1) return 0;
    if(i >= v[ith].size() || i < 0) return 0;
    if(dp[ith][i] != -1) return dp[ith][i];

    int ret = v[ith][i];
    if(ith >= n-1){
        ret += max(dpkoro(ith + 1, i), dpkoro(ith + 1, i - 1));
    }
    else{
        ret += max(dpkoro(ith + 1, i), dpkoro(ith + 1, i + 1));
    }

    return dp[ith][i] = ret;
}

void solve(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i = n, j = n-2; i < 2 * n - 1; i++, j--){
        for(int k = 0; k <= j; k++){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dpkoro(0, 0) << endl;

    for(int i = 0; i <= 2 * n; i++) v[i].clear();
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
