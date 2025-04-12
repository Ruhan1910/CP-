#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);


void solve(){
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] != i){
            res++;
            swap(v[i], v[v[i]]);
            i--;
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
