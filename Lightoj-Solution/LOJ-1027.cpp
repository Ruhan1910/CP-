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

void solve(){
    int n; cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    if(v[n-1] < 0){
        cout << "inf" << endl;
        return;
    }

    int res = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        res += abs(v[i]);
        if(v[i] > 0) cnt++;
    }

    int g = __gcd(res, cnt);
    cout << res/g << "/" << cnt/g << endl;
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
