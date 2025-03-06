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

int vis[26][26][26], res[26][26][26];
string st, ds;
int fx[] = {1, -1, 0, 0, 0, 0};
int fy[] = {0, 0, 1, -1, 0, 0};
int fz[] = {0, 0, 0, 0, 1, -1};
int n;

void bfs(){
    vis[st[0] - 'a'][st[1] - 'a'][st[2] - 'a'] = 1;
    res[st[0] - 'a'][st[1] - 'a'][st[2] - 'a'] = 0;
    bool flag = 0;

    queue<pair<pair<int, int>, int>> q;
    q.push({{st[0] - 'a', st[1] - 'a'}, st[2] - 'a'});

    while(!q.empty()){
        auto [xx, z] = q.front(); q.pop();
        if(xx.first == ds[0] - 'a' && xx.second == ds[1] - 'a' && z == ds[2] - 'a'){
            flag = 1; break;
        }

        int x = xx.first;
        int y = xx.second;


        for(int i = 0; i < 6; i++){
            int tx = (x + fx[i] + 26) % 26;
            int ty = (y + fy[i] + 26) % 26;
            int tz = (z + fz[i] + 26) % 26;

            if(!vis[tx][ty][tz]){
                vis[tx][ty][tz] = 1;
                res[tx][ty][tz] = res[x][y][z] + 1;
                q.push({{tx, ty}, tz});
            }
        }
    }

    if(flag) cout << res[ds[0] - 'a'][ds[1] - 'a'][ds[2] - 'a'] << endl;
    else cout << -1 << endl;
}


void solve() {
    cin >> st >> ds >> n;
    for(int i = 0; i < n; i++){
        string a, b, c;
        cin >> a >> b >> c;
        for(int j = 0; j < a.size(); j++){
            for(int k = 0; k < b.size(); k++){
                for(int l = 0; l < c.size(); l++){
                    vis[a[j] - 'a'][b[k] - 'a'][c[l] - 'a'] = 1;
                }
            }
        }
    }
    if(vis[st[0] - 'a'][st[1] - 'a'][st[2] - 'a']){
        cout << -1 <<endl;
    }
    else bfs();

    memset(vis, 0, sizeof(vis));
    memset(res, 0, sizeof(res));
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
