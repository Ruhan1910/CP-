#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const int N = 1e3 + 5;
int n, e;
vector<int>adj[N];
int vis[N], val[N], sum, cnt, prv;

void dfs(int u){
    vis[u] = 1;
    sum += val[u];
    cnt++;
    for(auto v:adj[u]){
        if(!vis[v]) dfs(v);
    }
}


void solve() {
    cin >> n >> e;
    for(int i = 1; i <= n; i++) cin >> val[i];

    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int flag = 1; prv = -1;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            sum = 0, cnt = 0;
            dfs(i);
            if(sum % cnt != 0){
                flag = 0; break;
            }
            if(prv == -1) prv = sum / cnt;
            else if(prv != (sum / cnt)){
                flag = 0; break;
            }
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
    }
}


int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
