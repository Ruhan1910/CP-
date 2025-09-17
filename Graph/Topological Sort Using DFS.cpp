//Time complexity O(n + e)

vector<vector<int>>graph;
bool vis[100];
int n,e;
stack<int>st;

void dfs(int s){
    vis[s]=1;
    for(auto child:graph[s]){
        if(!vis[child]) dfs(child);
    }
    st.push(s);
}

void topologicalsort(){
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void solve(){
    memset(vis,0,sizeof(vis));
    cin>>n>>e;
    graph.resize(n);
    for(int i=0; i<e; i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
    }
    topologicalsort();
}
