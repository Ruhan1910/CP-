//Time complexity O(n * n)
vector<int>graph[105];
bool taken[105];
int n,e;
map<string,int>mp1;
map<int,string>mp2;
map<int,int>indeg;
vector<int>res;

void topologicalsort(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!indeg[j] && !taken[j]){
                res.push_back(j);
                taken[j]=1;
                for(auto child:graph[j]) indeg[child]--;
                break;
            }
        }
    }
}

void solve(){
    n,e; cin>>n>>e;
    for(int i=0; i<e; i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        indeg[y]++;
    }

    topologicalsort();
    for(auto i:res) cout<<i<<" ";
}
