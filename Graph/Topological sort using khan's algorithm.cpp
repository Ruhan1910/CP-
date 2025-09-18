//Time complexity O(n + e)

const int N = 1e5;
vector<vector<int>>graph;
int indeg[N];
int n,e;

void dfs(int s){
    vis[s]=1;
    for(auto child:graph[s]){
        if(!vis[child]) dfs(child);
    }
    st.push(s);
}

void topologicalsort(){
    queue<int> q;
    vector<int> res;

    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        res.push_back(u);

        for(auto v : graph[u]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    for(auto it : res){
        cout << i << " ";
    }
    cout << endl;
}

void var_clear(int n){
    for(int i = 0; i <= n; i++){
        graph[i].clear();
        indeg[i] = 0;
    }
}

void solve(){
    cin>>n>>e;
    var_clear();
    graph.resize(n);

    for(int i=0; i<e; i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        indeg[y]++;
    }

    topologicalsort();
}
