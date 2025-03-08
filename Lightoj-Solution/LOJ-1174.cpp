#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<ll>
#define vl vector<ll>
#define m_p make_pair
#define pb push_back
#define fi first
#define sc second
#define PI acos(-1.0)
#define mod 1000000007
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);
#define Check(n,pos) (n & (1<<pos))
#define Set(n,pos) (n  (1<<pos))
//-------------------------------------------------------------------
#define SZ 1000005
ll MARK[SZ+1];
vector<ll>PRIME;

void sieve(){
    MARK[1]=1;
    ll root=sqrt(SZ);
    MARK[0]=MARK[1]=1;
    for(ll i=4; i<SZ; i+=2) MARK[i]=1;

    for(ll i=3; i<=root; i+=2){
        if(!MARK[i]){
            for(ll j=i*i; j<=SZ; j+=(i*2)){
                MARK[j]=1;
            }
        }
    }
    PRIME.push_back(2);
    for(ll i=3; i<=SZ; i+=2){
        if(!MARK[i]) PRIME.push_back(i);
    }
    return;
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll BigMod(ll a, ll p, ll m){
    ll ret=1;
    while(p){
        if(p&1) ret=((ret%m)*(a%m))%m;
        a=((a%m)*(a%m))%m;
        p/=2;
    }
    return ret;
}
ll AddMul(ll a, ll p, ll m){
    ll ret=0;
    while(p){
        if(p&1) ret=((ret%m)+(a%m))%m;
        a=((a%m)+(a%m))%m;
    }
    return ret;
}
void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
//--------------------------------------------------------------------
int n,v,x,y;
int vis[500], dis1[500], dis2[500];
vector<int>vv[500];

void bfs(int s, int *dis){
    vis[s]=1;
    dis[s]=0;
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto i:vv[top]){
            if(vis[i]==0){
                vis[i]=1;
                dis[i]=dis[top]+1;
                q.push(i);
            }
        }
    }
}

void solve(){
    cin>>n>>v;
    memset(vv,0,sizeof(vv));
    for(int i=0; i<v; i++){
        cin>>x>>y;
        vv[x].push_back(y);
        vv[y].push_back(x);
    }
    cin>>x>>y;

    ///Distance of all node from starting node
    memset(vis,0,sizeof(vis));
    bfs(x,dis1);

    ///Distance of all node from ending node
    memset(vis,0,sizeof(vis));
    bfs(y,dis2);

    int ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans, dis1[i]+dis2[i]);
    }

    cout<<ans<<endl;
}


int main(){
    //clock_t ct; ct = clock();
    fastio;
    //sieve();
    iofile();
    ll t=1, tc=1;
    cin>>t;
    //cin.ignore();
    while(t--){
        cout<<"Case "<<tc++<<": ";
        solve();
    }
    //ct = clock() - ct; double time_taken = ((double)ct)/CLOCKS_PER_SEC; cout<<time_taken<<endl;

    return 0;
}
