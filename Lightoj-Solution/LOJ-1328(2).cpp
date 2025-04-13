#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

int mod = 1e6 + 7;
void solve(){
    ll k, c, n, prv;
    cin >> k >> c >> n >> prv;

    vector<ll>v(n);
    v[0] = prv;

    for(int i = 1; i < n; i++){
        ll x = (k * v[i - 1] + c) % mod;
        v[i] = x;
    }
    sort(v.begin(), v.end());

    ll res = 0, temp = 0;
    for(int i = 1; i < n; i++){
        //First calculate the contribution of (v[i] - v[i - 1]) to all
        //it's previous sub array (i * (v[i] - v[i - 1])) then add this
        //temp because next in each upcoming subarray this value will 
        //be added
        temp += i * (v[i] - v[i - 1]);
        res += temp;
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
