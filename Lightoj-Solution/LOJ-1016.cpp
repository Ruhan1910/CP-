#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

string ask(int m){
    cout << "guess " << m << endl;
    string s; cin >> s;
    return s;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v[i] = y;
    }
    sort(v.begin(), v.end());

    int res = 1, prv = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] - prv > k){
            res++;
            prv = v[i];
        }
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
