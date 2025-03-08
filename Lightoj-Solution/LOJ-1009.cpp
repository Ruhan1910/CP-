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
vector<int>adj[N];
int vis[N], col[N];
int n, e;

int bfs(int s){
    int a = 0, b = 0;
    vis[s] = 1;
    col[s] = 1;
    a++;

    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
                col[v] = col[u] ^ 1;
                if(col[v] == 1) a++;
                else b++;
            }
        }
    }

    return max(a, b);
}

void clr(){
    for(int i = 0; i < N; i++){
        adj[i].clear();
        vis[i] = col[i] = 0;
    }
}

void solve() {
    int e; cin >> e;
    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = 0;
    for(int i = 1; i < N; i++){
        if(!vis[i] && !adj[i].empty()) res += bfs(i);
    }
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
