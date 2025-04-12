#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

vector<ll> dec_to_bin(ll n){
    vector<ll>ret;
    while(n){
        ret.push_back(n % 2);
        n /= 2;
    }

    return ret;
}

ll bin_to_dec(vector<ll> &v){
    ll ret = 0;
    for(int i = 0; i < v.size(); i++){
        ret *= 2;
        ret += v[i];
    }

    return ret;
}

void solve(){
    ll n; cin >> n;
    vector<ll>v = dec_to_bin(n);

    int flag = 0;
    for(int i = 1; i < v.size(); i++){
        if(v[i] == 0 && v[i - 1] == 1){
            swap(v[i], v[i - 1]);
            flag = 1;

            for(int j = 0, k = i - 2; j <= k; j++, k--){
                swap(v[j], v[k]);
            }

            break;
        }
    }

    if(!flag){
        int sz = v.size();
        int cnt = 0;
        for(int i = 0; i < sz; i++){
            if(v[i] == 1) cnt++;
        }

        v.clear();
        for(int i = 0; i <= sz; i++){
            if(i < cnt - 1) v.push_back(1);
            else if(i == sz) v.push_back(1);
            else v.push_back(0);
        }
    }

    reverse(v.begin(), v.end());
    n = bin_to_dec(v);

    cout << n << endl;
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
