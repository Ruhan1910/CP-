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
int vis[N], dis[N];
int n, mx, mx_node;

void dfs(int u, int d){
    vis[u] = 1;
    dis[u] = d;
    if(d > mx){
        mx = d; mx_node = u;
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

    int p, q;
    int disp[n], disq[n];

    mx = -1;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    dfs(0, 0);
    p = mx_node;

    mx = -1;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    dfs(p, 0);
    q = mx_node;
    for(int i = 0; i < n; i++) disp[i] = dis[i];

    mx = -1;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    dfs(q, 0);
    for(int i = 0; i < n; i++) disq[i] = dis[i];

    for(int i = 0; i < n; i++) cout << max(disp[i], disq[i]) << endl;
    clr();
}


int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ":\n";
        solve();
    }

    return 0;
}
