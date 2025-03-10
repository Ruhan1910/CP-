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
const int N = 1e5 + 5;
vector<vector<pair<int, int>>>adj(N);
int n, e, res, vis[N];

void mst_prims(int s){
    priority_queue<pair<int, int>>pq;
    pq.push({0, s});

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        d = -d;
        if(vis[u]) continue;

        res += d;
        vis[u] = 1;

        for(auto [v, w] : adj[u]){
            if(!vis[v]){
                pq.push({-w, v});
            }
        }
    }
}

void solve(){
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    res = 0;
    mst_prims(0);
    cout << res << endl;
}


int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
