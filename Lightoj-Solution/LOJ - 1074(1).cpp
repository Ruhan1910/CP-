//Using bellman ford
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

const int N = 1e5 + 5;
vector<pair<ll, ll>>adj[N];
vector<ll>temp(N);
ll n, e, dis[N], vis[N];
ll INF = 1e18;

void bellman_ford(int s){
	for(int i = 1; i <= n; i++){
        dis[i] = INF;
	}
	dis[s] = 0;
	for(int i = 1; i < n; i++){
        for(int u = 1; u <= n; u++){
            for(auto [v, w] : adj[u]){
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
            }
        }
	}
}

void dfs(int u){
    vis[u] = 1;
    for(auto [v, w] : adj[u]){
        if(!vis[v]) dfs(v);
    }
}

void solve(){
   cin >> n;
   for(int i = 1; i <= n; i++){
     cin >> temp[i];
   }
   cin >> e;
   for(int i = 1; i <= e; i++){
     int u, v; cin >> u >> v;
     ll w = temp[v] - temp[u];
     w = w * w * w;

     adj[u].push_back({v, w});
   }


   bellman_ford(1);
   dfs(1);

   int q; cin >> q;
   while(q--){
     int x; cin >> x;
     if(!vis[x] || dis[x] < 3) cout << "?" << endl;
     else cout << dis[x] << endl;
   }

   for(int i = 0; i <= n; i++){
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
        cout << "Case " << tc++ << ":\n";
        solve();
    }

    return 0;
}
