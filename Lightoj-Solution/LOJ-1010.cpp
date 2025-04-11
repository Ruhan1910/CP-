#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);


void solve(){
    int r, c; cin >> r >> c;
    if(r > c) swap(r, c);

    if(r == 1) cout << c << endl;
    else{
        int x = (r & 1) ? ((r / 2) + 1) : (r / 2);
        int y = (c & 1) ? ((c / 2) + 1) : (c / 2);
        int res = (x * y) + ((r - x) * (c - y));

        if(r == 2){
            if(res & 1) res++;
            else res += c % 4;
        }

        cout << res << endl;
    }
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
