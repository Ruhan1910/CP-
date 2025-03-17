#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

const ll N = 1e4 + 5;
vector<pair<ll, ll>>adj[N];
ll n, e, ans, vis[N];

void clr(){
	for(int i = 0; i <= n; i++){
		adj[i].clear();
		vis[i] = 0;
	}
}

void dijkstra(){
	priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>>pq;
	pq.push({0, 1});
	set<ll>st;
	if(n == 1) st.insert(0);
	
	while(!pq.empty()){
		auto [d, u] = pq.top(); pq.pop();
		vis[u]++;
		if(vis[u] > 2) continue;
		
		for(auto [v, w] : adj[u]){
			if(vis[v] < 2){
				pq.push({d + w, v});
			}
			if(v == n) st.insert(d + w);
		}
	}
	auto it = st.begin(); it++;
	ans = *it;
}

void solve(){
   cin >> n >> e;
   for(int i = 0; i < e; i++){
   	ll u, v, w;
   	cin >> u >> v >> w;
   	adj[u].push_back({v, w});
   	adj[v].push_back({u, w});
   }
   dijkstra();
   cout << ans << endl;
   clr();
}

int main(){
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
