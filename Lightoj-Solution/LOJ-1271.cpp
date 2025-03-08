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
const int N = 5e4+5;
vector<int>adj[N], arr;
int vis[N], parent[N];
int n;

void bfs(int s, int d){
    vis[s] = 1;
    parent[s] = -1;

    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                parent[v] = u;
                if(v == d) return;
                q.push(v);
            }
        }
    }
}

void clr(){
    for(int i = 0; i < N; i++){
        adj[i].clear();
        vis[i] = parent[i] = 0;
    }
}

void solve(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0){
            adj[arr[i-1]].push_back(arr[i]);
            adj[arr[i]].push_back(arr[i-1]);
        }
    }
    for(int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());

    bfs(arr[0], arr[n-1]);
    int x = arr[n-1];
    vector<int>res;
    while(1){
        res.push_back(x);
        x = parent[x];
        if(x == -1) break;
    }

    reverse(res.begin(), res.end());
    for(auto it:res) cout << it << " ";
    cout << endl;

    clr();
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
