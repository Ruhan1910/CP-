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
const int N = 105;
vector<int>adj[N];
int vis_with_carry[N], vis_without_carry[N];
int n, e, res;

void bfs(int s){
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto v:adj[u]){
            if(!vis_without_carry[v] && (vis_with_carry[u] || u == 1)){
                vis_without_carry[v] = 1;
                q.push(v);
            }
            if(!vis_with_carry[v] && vis_without_carry[u]){
                res++;
                vis_with_carry[v] = 1;
                q.push(v);
            }
        }
    }
}

void clr(){
    for(int i = 0; i <= n; i++){
        vis_with_carry[i] = 0;
        vis_without_carry[i] = 0;
        adj[i].clear();
    }
}

void solve(){
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    res = 0;
    bfs(1);
    cout << res << endl;

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
