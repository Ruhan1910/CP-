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
const int N = 105;
char graph[N][N];
int vis[N][N];
int r, c, res;
int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

bool valid(int x, int y){
    return (x >= 0 && x < r && y >= 0 && y < c);
}

void dfs(int x, int y){
    vis[x][y] = 1; res++;

    for(int i = 0; i < 4; i++){
        int cx = x + fx[i];
        int cy = y + fy[i];

        if(valid(cx, cy) && !vis[cx][cy] && (graph[cx][cy] == '.')){
            dfs(cx, cy);
        }
    }
}

void clr(){
    memset(vis, 0, sizeof(vis));
}

void solve() {
    cin >> c >> r;
    int sx, sy;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> graph[i][j];
            if(graph[i][j] == '@'){
                sx = i; sy = j;
            }
        }
    }


    res = 0;
    dfs(sx, sy);
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
