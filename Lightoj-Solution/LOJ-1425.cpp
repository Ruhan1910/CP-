#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

const int N = 1e5 + 5;
vector<int>v(N);
int n;

bool possible(int k){
    int prv = 0;
    for(int i = 0; i < n; i++){
        if(v[i] - prv > k) return false;
        if(v[i] - prv == k) k--;
        prv = v[i];
    }

    return true;
}

void solve(){ 
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0, r = 2e9, res;
    while(l <= r){
        int m = (l + r) / 2;
        if(possible(m)){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
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
