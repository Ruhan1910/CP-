#include<bits/stdc++.h>
using namespace std;
#define endl '\n' //change during interactive problems
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define sc second
#define check(n , k) (n & (1LL << k))
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define toggle(n, k) (n ^ (1 << k));
#define count_on_bit(n) __builtin_popcount(n);
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0);

//Try to look at it from a whole new angle
//Why your way of thinking was not correct and what did you miss?
//What did you learn from this problem?
//Main goal is to learn new stuff

const int N = 1e6 + 5;
bitset<N> MARK;
vector<int> PRIME, LP(N);

void sieve(){
    MARK[0] = MARK[1] = 1;
    for(int i = 0; i < N; i++){
        LP[i] = i;
    }
    for(int i = 4; i < N; i += 2){
        MARK[i] = 1; 
        LP[i] = 2;
    }

    for(int i = 3; i * i < N; i += 2){
        if(!MARK[i]){
            for(int j = i * i; j < N; j += (i * 2)){
                MARK[j] = 1;
                LP[j] = min(LP[j], i);
            }
        }
    }
    
    PRIME.push_back(2);
    for(int i = 3; i < N; i += 2){
        if(!MARK[i]) PRIME.push_back(i);
    }
    return;
}

ll AddMul(ll a, ll p, ll m){
    ll ret=0;
    while(p){
        if(p&1) ret=((ret%m)+(a%m))%m;
        a=((a%m)+(a%m))%m;
        p /= 2;
    }
    return ret;
}

ll BigMod(ll a, ll p, ll m){
    ll ret = 1; a %= m;
    while(p){
        if(p & 1) ret = AddMul(ret, a, m);
        a = AddMul(a, a, m);
        p /= 2;
    }
    return ret;
}

bool is_composite(ll n, ll a, ll d, ll s){
    ll x = BigMod(a, d, n);

    if(x == 1 || x == n - 1) return false;

    for(int r = 1; r < s; r++){
        x = AddMul(x, x, n);
        if(x == n - 1) return false;
    }

    return true;
}

bool isprime(ll n){
    if(n == 1) return false;
    if(n % 2 == 0 && n != 2) return false;
    if(n == 2 || n == 3) return true;

    vector<ll> temp = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    int s = 0;
    ll d = n - 1;
    while(!(d & 1)){
        d /= 2; s++;
    }

    for(auto a : temp){
        if(n % a == 0) return n == a;
        if(is_composite(n, a, d, s)) return false;
    }

    return true;
}

ll pollard_rho(ll n, ll c){
    ll x=2, y=2, i=1, k=2, d;
    while(true){
        x=(AddMul(x, x, n)+c);
        if(x>=n) x-=n;
        d=__gcd(abs(x-y),n);
        if(d>1) return d;
        if(++i==k){
            y=x, k<<=1;
        }
    }
    return n;
}

void llfactorize(ll n, vector<ll> &f){
    if(n == 1) return;
    if(n < 1e9){
        for(int i = 0; PRIME[i] * PRIME[i] <= n && i < PRIME.size(); i++){
            ll p = PRIME[i];
            while(n % p == 0){
                f.push_back(p);
                n /= p;
            }
        }
        if(n > 1) f.push_back(n);
        return;
    }

    if(isprime(n)){
        f.push_back(n);
        return;
    }

    ll d = n;
    for(ll i = 2; d == n; i++){
        d = pollard_rho(n, i);
    }

    llfactorize(d, f);
    llfactorize(n / d, f);
}

void factorize(ll n, vector<pll> &ans){
    vector<ll> v;
    llfactorize(n, v);
    if(v.size() == 0) return;

    ll a = v[0], b = 1;
    for(ll i = 1; i < v.size(); i++){
        if(v[i] == v[i - 1]) b++;
        else{
            ans.push_back({a, b});
            a = v[i];
            b = 1;
        }
    }
    ans.push_back({a, b});
}

void solve(){
    ll n; cin >> n;
    vector<pll> v;
    factorize(n, v);

    vector<ll> res;
    for(auto [p, c] : v){
        while(c--){
            res.push_back(p);
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << " ";
    for(auto it : res) cout << it << " ";
        cout << endl;
}

int main(){
    sieve();
    fastio;
    int t=1, tc=1;
    cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
