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

char a[100][100];
int vis[100][100], dis[100][100];
int fx[] = {0, 0, -1, 1};
int fy[] = {1, -1, 0, 0};
int r, c, res;

bool valid(int x, int y){
    return (x >= 0 && x < r && y >= 0 && y < c && a[x][y] != '#'&& a[x][y] != 'm');
}

void bfs(int x, int y){
    vis[x][y] = 0;
    dis[x][y] = 0;
    queue<pair<int, int>>q;
    q.push({x, y});

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int tx = cx + fx[i];
            int ty = cy + fy[i];
            if(valid(tx, ty) && !vis[tx][ty]){
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[cx][cy] + 1;
                q.push({tx, ty});

                if(a[tx][ty] == 'h'){
                    res = max(res, dis[tx][ty]);
                    return;
                }
            }
        }
    }
}


void solve() {
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }

    res = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 'a' || a[i][j] == 'b' || a[i][j] == 'c'){
                memset(vis, 0, sizeof(vis));
                memset(dis, 0, sizeof(dis));
                bfs(i, j);
            }
        }
    }

    cout << res << endl;
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
