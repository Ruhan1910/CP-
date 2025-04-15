#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

ll n, r, mod = 142857;

vector<pair<ll, ll>> prime_fac(ll x){
    vector<pair<ll, ll>>ret;
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0){
            ll cnt = 0;
            while(x % i == 0){
                x /= i;
                cnt++;
            }
            ret.push_back({i, cnt});
        }
    }
    if(x > 1) ret.push_back({x, 1});

    return ret;
}

ll BigMod(ll a, ll p, ll m){
    ll ret = 1;
    while(p){
        if(p & 1) ret = ((ret % m) * (a % m)) % m;
        a = ((a % m) * (a % m)) % m;
        p /= 2;
    }
    return ret;
}

ll modular_inverse(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = modular_inverse(b, a % b, x1, y1);
    x = y1;
    y = x1 - (y1 * (a / b));
    return g;
}

ll fact[100005];
void cal_fact(ll p, ll m){
    fact[0] = 1;
    for(ll i = 1; i < m; i++){
        fact[i] = (fact[i - 1] * ((i % p) ? i : 1)) % m;
    }
}

ll spf(ll x, ll p, ll m){
    ll res = BigMod(fact[m - 1], x / m, m);
    if(x >= p) res = (res * spf(x / p, p, m)) % m;
    return (res * fact[x % m]) % m;
}

ll nCr_mod_pq(ll p, ll q){
    ll a = 0, b = 0, c = 0;
    ll xx = p;
    while(xx <= n){
        a += n / xx;
        xx *= p;
    }

    xx = p;
    while(xx <= r){
        b += r / xx;
        xx *= p;
    }

    xx = p;
    while(xx <= (n - r)){
        c += (n - r) / xx;
        xx *= p;
    }

    ll z = a - b - c;
    if(z >= q) return 0LL;

    ll m = BigMod(p, q, mod);//power(p, q)
    cal_fact(p, m);

    ll ret = BigMod(p, z, m);//power(p, z)
    
    a = spf(n, p, m);
    ret = (ret * a) % m;

    b = spf(r, p, m);
    ll x, y;
    modular_inverse(b, m, x, y);
    x %= m; 
    if(x < 0) x += m;
    ret = (ret * x) % m;

    c = spf(n - r, p , m);
    modular_inverse(c, m, x, y);
    x %= m;
    if(x < 0) x += m;
    ret = (ret * x) % m;

    return ret;
}

ll nCr_mod_m(){
    vector<pair<ll, ll>>pf = prime_fac(mod);

    ll p1 = pf[0].first, q1 = pf[0].second;
    ll m1 = BigMod(p1, q1, 1e8);/*power of(p1, q1)*/
    ll a1 = nCr_mod_pq(p1, q1);
    ll x = a1;

    for(int i = 1; i < pf.size(); i++){
        ll p2 = pf[i].first, q2 = pf[i].second;
        ll m2 = BigMod(p2, q2, 1e8); //power(p2, q2); 
        ll a2 = nCr_mod_pq(p2, q2);

        ll p, q, M;
        M = m1 * m2;
        modular_inverse(m1, m2, p, q);
        x = ((a1 * m2 * q) % M + (a2 * m1 * p) % M) % M;

        m1 = M;
        a1 = x % M;
    }

    return x;
}

void solve() {
    cin >> n >> r;
    cout << nCr_mod_m() << endl;
}

int main(){
    fastio;
    int t=1, tc=1;
    cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
