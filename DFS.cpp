void dfs(int u /*extra parameter*/){
    vis[u] = 1;
    //extra calculation
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
