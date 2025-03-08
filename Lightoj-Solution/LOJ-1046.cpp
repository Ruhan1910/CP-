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
char a[11][11];
int vis[11][11], cost[11][11];
int r, c, cnt, temp, res;
int fx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int fy[] = {1, -1, 1, -1, 2, 2, -2, -2};

bool valid(int x, int y){
    return (x >= 0 && x < r && y >= 0 && y < c);
}

void bfs(int x, int y){
    vis[x][y] = 1;
    cost[x][y] = 0;
    if(a[x][y] != '.') cnt++;
    queue<pair<int, int>>q;
    q.push({x, y});

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int tx = cx + fx[i];
            int ty = cy + fy[i];

            if(valid(tx, ty) && !vis[tx][ty]){
                vis[tx][ty] = 1;
                cost[tx][ty] = cost[cx][cy] + 1;
                q.push({tx, ty});

                if(a[tx][ty] != '.'){
                    int xx = a[tx][ty] - '0';
                    cnt++;
                    temp += (cost[tx][ty] + xx - 1) / xx;
                }
            }
        }
    }
}

void solve() {
    cin >> r >> c;
    int tot = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] != '.') tot++;
        }
    }

    res = 1e9;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            memset(vis, 0, sizeof(vis));
            memset(cost, 0, sizeof(cost));
            temp = 0; cnt = 0;
            bfs(i, j);
            if(cnt == tot) res = min(res, temp);
        }
    }

    if(res == 1e9) cout << - 1 << endl;
    else cout << res << endl;
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
