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

///Find bridges in a given graph. Bridges are that edge if we remove
///it from the graph then number of connected component of that tree
///will increase. multiple edge and self loop can exist in this case.

const int N = 1e5 + 5;
vector<vector<int>>adj(N);
int vis[N], tin[N], low[N];
int n, e, timer, bridges;

void dfs(int u, int p){
    vis[u] = 1;
    //store visited time and low of current node
    tin[u] = low[u] = timer++;
    bool parent_skipped = 0;

    for(auto v : adj[u]){
        //Handle multiple edges
        if(v == p && !parent_skipped){
            parent_skipped = 1;
            continue;
        }

        //we are going to v from u. (u->v) If v is not
        //parent of u and already visited we will change
        //the low of current node to keep track there exist
        //a node which have a back-edge or a edge to ancestor
        //so there are no bridges here

        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);

            //when we are going back after traverse we will
            //update the parent low with every child of it.
            //Because there might be an edge from it's descendant's
            //to it's ancestor. For this the low value will decrease.
            low[u] = min(low[u], low[v]);

            //If above scenario will not happen. Then there are no
            //edge from it's descendant's to it's ancestor. So the
            //low value of it's child will stay higher then parent's
            //means current node. It means (u->v) is a bridges.
            if(low[v] > tin[u]){
                bridges++;
            }
        }
    }
}

void solve(){
    cin >> n >> e;
    for(int i = 1; i <= e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //set the entry timer
    timer = bridges = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }
    cout << bridges << endl;
}


int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
