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

const int N = 5005;
vector<vector<pair<int, int>>>adj(N);
int n, e, dis1[N], dis2[N];
int INF = 1e9;

void clr(){
    for(int i = 0; i <= n; i++){
        adj[i].clear();
    }
}

void bfs(){
    queue<pair<int, int>>q;
    dis1[1] = 0;
    q.push({1, 0});
    while(!q.empty()){
        auto [u, d] = q.front(); q.pop();
        for(auto [v, w] : adj[u]){
            if(d + w < dis2[v]){
                if(d + w < dis1[v]){
                    dis2[v] = dis1[v];
                    dis1[v] = d + w;
                    q.push({v, d + w});
                }
                else if(d + w != dis1[v]){
                    dis2[v] = d + w;
                    q.push({v, d + w});
                }
            }
        }
    }

    cout << dis2[n] << endl;
}

void solve(){
   cin >> n >> e;
   for(int i = 0; i < e; i++){
     int u, v, w; cin >> u >> v >> w;
     adj[u].push_back({v, w});
     adj[v].push_back({u, w});
   }
   for(int i = 0; i <= n; i++) dis1[i] = dis2[i] = INF;
   bfs();
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
