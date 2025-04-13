#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);


void solve(){
    int n; cin >> n;
    vector<pair<int, int>>v;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, 0});
        v.push_back({y, 1});
    }

    sort(v.begin(), v.end());
    int res = 0, temp = 0;
    for(int i = 0; i < 2 * n; i++){
        if(v[i].second == 0) temp++;
        else temp--;
        res = max(res, temp);
    }

    cout << res << endl;
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
