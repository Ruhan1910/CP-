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

const int N = 1e5;
vector<pair<int, pair<int, int>>>edge;
int n, e, p[N];

int find_set(int n){
    if(p[n] == n) return n;
    return find_set(p[n]);
    //We can use path compression
}

void mst_kruskal(){
    sort(edge.begin(), edge.end());
    for(int i = 1; i <= n; i++) p[i] = i;

    int cnt = 0, dis = 0;
    for(auto it : edge){
        auto [w, x] = it;
        auto [a, b] = x;
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            //Here we can use optimization with size
            //For faster code
            p[b] = a;
            cnt++; dis += w;
            if(cnt == n - 1) break;
        }
    }

    cout << dis << endl;
}

void solve(){
   cin >> n >> e;
   for(int i = 1; i <= e; i++){
     int u, v, w; cin >> u >> v >> w;
     edge.push_back(make_pair(w, make_pair(u, v)));
   }

   mst_kruskal();
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
