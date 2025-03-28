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

void make_permutation(int ind, string s, vector<string> &ans){
    if(ind == s.size()){
        ans.push_back(s);
        return;
    }

    for(int i = ind; i < s.size(); i++){
        swap(s[ind], s[i]);
        make_permutation(ind + 1, s, ans);
        swap(s[ind], s[i]);
    }
}

vector<string> find_permutation(string s){
    vector<string>ret;
    make_permutation(0, s, ret);
    sort(ret.begin(), ret.end());

    return ret;
}

void solve(){
    string s; cin >> s;
    vector<string>per = find_permutation(s);

    for(auto it : per) cout << it << endl;
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
