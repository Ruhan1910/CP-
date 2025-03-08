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
const int mx=205;
char s[mx][mx];
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
int n, r, c, sx, res, sy, vis[mx][mx], dis[mx][mx], fire_time[mx][mx];
queue<pair<int, pair<int, int>>>q;

bool valid(int x, int y){
    return (x >= 0 && x <= r + 1 && y >= 0 && y <= c + 1 && s[x][y] != '#');
}

void bfs(){
    while(!q.empty()){
        int type = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int tx = cx + fx[i];
            int ty = cy + fy[i];

            if(valid(tx, ty) && !vis[tx][ty]){
                if(type == 1){
                    if(s[tx][ty] != 'X'){
                        s[tx][ty] = '#';
                        vis[tx][ty] = 1;
                        q.push({1, {tx, ty}});
                    }
                }
                else{
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[cx][cy] + 1;
                    q.push({0, {tx, ty}});

                    if(s[tx][ty] == 'X'){
                        res = min(res, dis[tx][ty]);
                        //return;
                    }
                }


            }
        }
    }
}

void solve(){
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    cin >> r >> c;

    for(int i = 0; i <= r+1; i++){
        for(int j = 0; j <= c+1; j++){
            if(i > 0 && i < r + 1 && j > 0 && j < c + 1){
                cin >> s[i][j];
                if(s[i][j] == 'J'){
                    sx = i; sy = j;
                }
                if(s[i][j] == 'F'){
                    s[i][j] = '#';
                    q.push({1, {i, j}});
                }
            }
            else s[i][j] = 'X';
        }
    }
    dis[sx][sy] = 0;
    vis[sx][sy] = 1;
    q.push({0, {sx, sy}});
    res = 1000;
    bfs();

    if(res == 1000) cout << "IMPOSSIBLE" << endl;
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
