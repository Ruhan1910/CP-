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
    vector<pair<int, int>>adj[105];
    bool vis[105];
    int n;

    int dfs(int u){
        vis[u] = 1;
        int ret = 0;
        for(auto [v, w]:adj[u]){
            if(!vis[v]){
                ret += w + dfs(v);
            }
        }
        return ret;
    }

    void solve() {
        cin >> n;
        for(int i = 0; i < n; i++){
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v, 0});
            adj[v].push_back({u, w});
        }

        int res = 1e9;
        for(int i = 0; i < 2; i++){
            vis[1] = 1;
            int another_city = adj[1][i ^ 1].first;
            int another_city_cost = (adj[another_city][0].first == 1) ? adj[another_city][0].second : adj[another_city][1].second;

            int temp = adj[1][i].second + dfs(adj[1][i].first) + another_city_cost;
            res = min(res, temp);
            memset(vis, 0, sizeof(vis));
        }

        cout << res << endl;

        for(int i = 0; i <= n; i++) adj[i].clear();
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
