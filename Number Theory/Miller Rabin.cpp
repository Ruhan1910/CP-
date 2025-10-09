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
