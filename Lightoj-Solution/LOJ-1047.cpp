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

int dp[25][4];
vector<vector<int>>v(25, vector<int>(3));
int n;

int dpkoro(int ind, int prv){
    if(ind == n) return 0;
    if(dp[ind][prv] != -1) return dp[ind][prv];

    int ret = 1e9;
    for(int i = 0; i < 3; i++){
        if(i == prv) continue;
        ret = min(ret, v[ind][i] + dpkoro(ind + 1, i));
    }

    return dp[ind][prv] = ret;
}

void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j];
        }
    }

    cout << dpkoro(0, 3) << endl;
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
