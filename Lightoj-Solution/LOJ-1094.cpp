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
const int N = 3e4 + 5;
vector<pair<int, int>>adj[N];
int vis[N];
int n, mx, first;

void dfs(int u, int d){
    vis[u] = 1;
    if(d > mx){
        mx = d; first = u;
    }

    for(auto [v, w]:adj[u]){
        if(!vis[v]){
            dfs(v, d + w);
        }
    }
}

void clr(){
    for(int i = 0; i <= n; i++) adj[i].clear();
}

void solve() {
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    mx = -1;
    memset(vis, 0, sizeof(vis));
    dfs(0, 0);

    mx = -1;
    memset(vis, 0, sizeof(vis));
    dfs(first, 0);

    cout << mx << endl;
    clr();
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
