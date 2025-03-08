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
const int mx=20;
char s[mx][mx], mx_ch, next_ch;
int vis[mx][mx], dis[mx][mx];
map<char, pair<int, int>>mp;
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
int n;

bool valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && (s[x][y] == '.' || s[x][y] == next_ch));
}

void bfs(int x, int y){
    vis[x][y] = 1;
    dis[x][y] = 0;
    s[x][y] = '.';
    queue<pair<int, int>>q;
    q.push({x, y});

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int tx = cx + fx[i];
            int ty = cy + fy[i];

            if(valid(tx, ty)){
                s[x][y] = '.';
                vis[tx][ty] = 1;
                dis[tx][ty] = dis[cx][cy] + 1;
                q.push({tx, ty});

                if(s[tx][ty] == next_ch) return;
            }
        }
    }
}

void solve(){
    cin >> n;
    mx_ch = 'A';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
            mp[s[i][j]] = {i, j};
            if(isalpha(s[i][j])) mx_ch = max(mx_ch, s[i][j]);
        }
    }
    //cout << mx_ch << endl;

    int res = 0;

    for(char i = 'A'; i < mx_ch; i++){
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));

        next_ch = i+1;
        bfs(mp[i].first, mp[i].second);

        int x = mp[next_ch].first;
        int y = mp[next_ch].second;
        if(dis[x][y] == 0){
            cout << "Impossible" << endl;
            return;
        }
        res += dis[x][y];
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
