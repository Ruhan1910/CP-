#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void solve(){
    int n; cin >> n;
    map<int, int>mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mp[i]){
            cnt++; mp[i]--;
        }
        else if(mp[n - i - 1]){
            cnt++; mp[n - i - 1]--;
        }
    }

    if(cnt == n) cout << "yes" << endl;
    else cout << "no" << endl;
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
