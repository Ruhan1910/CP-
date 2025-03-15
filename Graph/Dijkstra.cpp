#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

const int N = 1e5 + 5;
vector<pair<int, int>>adj[N];
int n, e, dis[N];
int INF = 1e9;

void dijkstra(int s){
	dis[s] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({s, 0});
	
	while(!pq.empty()){
		auto [u, d] = pq.top(); pq.pop();
		d = -d;
		for(auto [v, w] : adj[u]){
			if(dis[u] + w < dis[v]){ //dis[u] == d
				dis[v] = dis[u] + w;
				pq.push({v, -dis[v]});
			}
		}
	}
}

void solve(){
   cin >> n >> e;
   for(int i = 0; i < e; i++){
   	int u, v, w;
   	cin >> u >> v >> w;
   	adj[u].push_back({v, w});
   	adj[v].push_back({u, w});
   }
   
   for(int i = 0; i < n; i++) dis[i] = INF;
   dijkstra(0);
   
   for(int i = 0; i < n; i++) cout << dis[i] << endl;
}

int main(){
    int t=1, tc=1;
    cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ":\n";
        solve();
    }

    return 0;
}
