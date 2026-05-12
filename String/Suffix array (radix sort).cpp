#include<bits/stdc++.h>
using namespace std;
#define endl '\n' //change during interactive problems
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define sc second
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0);


void counting_sort(vector<pair<pii, int>> &v){
    int n = v.size();
    vector<int> cnt(n);
    for(auto it : v){
        cnt[it.fi.sc]++;
    }
    for(int i = 1; i < n; i++){
        cnt[i] += cnt[i - 1];
    }

    vector<pair<pii, int>> v_new(n);
    for(int i = n - 1; i >= 0; i--){
        v_new[cnt[v[i].fi.sc] - 1] = v[i];
        cnt[v[i].fi.sc]--;
    }

    v = v_new;
    for(int i = 0; i < n; i++){
        swap(v[i].fi.fi, v[i].fi.sc);
    }
}

void redix_sort(vector<pair<pii, int>> &v){
    counting_sort(v);
    counting_sort(v);
}

void solve(){
    string s; cin >> s;
    s += '$';
    int n = s.size();

    vector<int> p(n), c(n);
    //k = 0
    vector<pair<char, int>> v(n);
    for(int i = 0; i < n; i++){
        v[i] = {s[i], i};
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        p[i] = v[i].sc;
    }
    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(v[i].fi == v[i - 1].fi) c[p[i]] = c[p[i - 1]];
        else c[p[i]] = c[p[i - 1]] + 1;
    }

    //k > 0
    int k = 0;
    while((1 << k) < n){
        vector<pair<pii, int>> vp(n);
        for(int i = 0; i < n; i++){
            vp[i].fi.fi = c[i];
            vp[i].fi.sc = c[(i + (1 << k)) % n];
            vp[i].sc = i;
        }

        redix_sort(vp);
        for(int i = 0; i < n; i++){
            p[i] = vp[i].sc;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(vp[i].fi == vp[i - 1].fi) c[p[i]] = c[p[i - 1]];
            else c[p[i]] = c[p[i - 1]] + 1;
        }
        k++;
    }

    for(int i = 0; i < n; i++){
        cout << p[i] << " ";
    }
    cout << endl;
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
