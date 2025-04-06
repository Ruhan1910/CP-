#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

ll N, W;
ll v[105], w[105];
ll dp[105][100005];

ll dpkoro(int ind, int temp){
    if(ind >= N) return 0;
    if(dp[ind][temp] != 0) return dp[ind][temp];

    ll ret = dpkoro(ind + 1, temp);
    if(temp + w[ind] <= W) ret = max(ret, dpkoro(ind + 1, temp+w[ind]) + v[ind]);

    return dp[ind][temp] = ret;
}

void solve(){
    cin >> N >> W;
    for(int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }

    cout << dpkoro(0, 0) << endl;
}


int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
