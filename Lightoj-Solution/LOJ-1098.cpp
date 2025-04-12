#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);


void solve(){
    int n; cin >> n;
    vector<int> my_team(n), op_team(n);
    for(int i = 0; i < n; i++) cin >> my_team[i];
    for(int i = 0; i < n; i++) cin >> op_team[i];

    sort(my_team.begin(), my_team.end());
    sort(op_team.rbegin(), op_team.rend());

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(op_team[j] && (op_team[j] < my_team[i])){
                res += 2;
                my_team[i] = op_team[j] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(my_team[i]){
            for(int j = 0; j < n; j++){
                if(my_team[i] == op_team[j]){
                    res++; 
                    my_team[i] = op_team[j] = 0;
                    break;
                }
            }
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
