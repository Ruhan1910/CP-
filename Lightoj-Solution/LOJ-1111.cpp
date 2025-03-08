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
const int N = 1005;
vector<int>adj[N];
int vis[N], total[N], people[N];

void dfs(int u){
    vis[u] = 1;
    total[u]++;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}


void solve() {
    int k, n, e; cin >> k >> n >> e;
    int kk = 0;
    for(int i = 1; i <= k; i++){
        int x; cin >> x;
        if(people[x] == 0) kk++;
        people[x] = 1;

    }

    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(people[i]){
            dfs(i);
            memset(vis, 0 , sizeof(vis));
        }
    }

    int res = 0;
    for(int i = 1; i<= n; i++){
        if(total[i] == kk) res++;

        adj[i].clear();
        total[i] = 0;
        vis[i] = 0;
        people[i] = 0;
    }

    cout << res << endl;

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
