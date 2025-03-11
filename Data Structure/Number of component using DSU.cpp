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
vector<vector<int>>adj(N);
int n, e, parent[N], Size[N];

void make_set(){
    for(int i = 0; i <= n; i++){
        parent[i] = i;
        Size[i] = 1;
    }
}

int find_set(int n){
    if(parent[n] == n) return n;
    return parent[n] = find_set(parent[n]);
}

void Union(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

void solve(){
    cin >> n >> e;
    make_set();
    for(int i = 0; i < e; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        Union(u, v);
    }

    set<int>st;
    for(int i = 1; i <= n; i++) st.insert(parent[i]);

    cout << st.size() << endl;

}


int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ":\n";
        solve();
    }

    return 0;
}
