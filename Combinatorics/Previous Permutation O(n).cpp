#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> a = v;
    next_permutation(a.begin(), a.end());
    cout << "Next Permutaiton is: ";
    for(auto it : a) cout << it << " ";
    cout << endl;

    vector<int> b = v;
    prev_permutation(b.begin(), b.end());
    cout << "Previous Permutation is: ";
    for(auto it : b) cout << it << " ";
    cout << endl;
}

int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    //cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
