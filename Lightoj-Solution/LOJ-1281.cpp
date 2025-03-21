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
vector<pair<ll, pair<ll, ll>>>adj[N];
ll n, e, k, d, dis[N][20], res;
ll INF = 1e18;



void dijkstra(int s){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= d; j++){
            dis[i][j] = INF;
        }
    }
    dis[s][0] = 0;
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll,pair<ll, ll>>>, greater<pair<ll,pair<ll, ll>>>>pq;
    pq.push({0, {s, 0}});

    while(!pq.empty()){
        auto [dd, x] = pq.top(); pq.pop();
        ll u = x.first;
        ll extra = x.second;

        //if(dis[u][extra] < d) continue; //will reduce runtime but not matter

        for(auto [v, y] : adj[u]){
            ll w = y.first;
            ll tot = extra + y.second;
            if(tot > d) continue;

            if(dd + w < dis[v][tot]){
                dis[v][tot] = dd + w;
                pq.push({dd + w, {v, tot}});

                if(v == n-1) res = min(res, dd + w);
            }
        }
    }
}

void solve(){
   cin >> n >> e >> k >> d;
   for(int i = 1; i <= e; i++){
     ll u, v, w; cin >> u >> v >> w;
     adj[u].push_back({v, {w, 0}});
   }
   for(int i = 1; i <= k; i++){
     ll u, v, w; cin >> u >> v >> w;
     adj[u].push_back({v, {w, 1}});
   }
   res = INF;
   dijkstra(0);
   if(res == INF) cout << "Impossible" << endl;
   else cout << res << endl;

   for(int i = 0; i < n; i++){
    adj[i].clear();
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
