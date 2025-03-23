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

void make_permutation(int ind, vector<int>arr, vector<vector<int>> &ans){
    if(ind == arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i = ind; i < arr.size(); i++){
        swap(arr[ind], arr[i]);
        make_permutation(ind + 1, arr, ans);
        swap(arr[ind], arr[i]);
    }
}

vector<vector<int>> find_permutation(vector<int>arr){
    vector<vector<int>>ret;
    make_permutation(0, arr, ret);

    //For printing lexicographically shortest permutation
    sort(ret.begin(), ret.end());

    return ret;
}

void solve(){
    vector<int>arr;
    for(int i = 1; i <= 3; i++) arr.push_back(i);

    vector<vector<int>>per = find_permutation(arr);

    for(int i = 0; i < per.size(); i++){
        for(auto it : per[i]) cout << it << " ";
        cout << endl;
    }
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
