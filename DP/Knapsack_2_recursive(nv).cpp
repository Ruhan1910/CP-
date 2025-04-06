#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

ll n, w, inf = 1e15;
vector<ll>weight(101), value(101);
ll dp[101][100001];

ll dpkoro(int ind, int val){
    if(ind == n){
        if(val == 0) return 0;
        return inf;
    }
    if(dp[ind][val] != -1) return dp[ind][val];

    ll ret = dpkoro(ind + 1, val);
    if(value[ind] <= val) ret = min(ret, weight[ind] + dpkoro(ind + 1, val - value[ind]));

    return dp[ind][val] = ret;
}

void solve(){
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 100000; i >= 0; i--){
        if(dpkoro(0, i) <= w){
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main(){
    fastio;
    int t=1, tc=1;
    //cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
