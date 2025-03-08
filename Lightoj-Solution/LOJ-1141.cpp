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
const int N = 1e3 + 5;
int vis[N], dis[N];
int a, b;

bool is_prime(int n){
    if(n < 2) return false;
    if(n % 2 == 0 && n != 2) return false;

    for(int i = 3; i * i <= n; i+=2){
        if(n % i == 0) return false;
    }

    return true;
}

void bfs(int s){
    vis[s] = 1;
    dis[s] = 0;
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 2; i < u; i++){
            if(u + i > b) break;
            if(is_prime(i) && (u % i == 0) && (!vis[u + i])){
                dis[u + i] = dis[u] + 1;
                vis[u + i] = 1;
                q.push(u + i);
            }
        }
    }
}

void solve() {
    cin >> a >> b;
    bfs(a);
    if(vis[b]) cout << dis[b] << endl;
    else cout << -1 << endl;
    //cout << dis[b] << endl;

    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
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
