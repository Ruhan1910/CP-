using u64 = uint64_t;
using u128 = __uint128_t;

//If time limit is not tighnt then we can use AddMul
//instead of u64 and u128. This will take more time
ll AddMul(ll a, ll p, ll m){
    ll ret=0;
    while(p){
        if(p&1) ret=((ret%m)+(a%m))%m;
        a=((a%m)+(a%m))%m;
        p /= 2;
    }
    return ret;
}

u64 BigMod(u64 a, u64 p, u64 m){
    u64 ret = 1; a %= m;
    while(p){
        if(p & 1) ret = (u128)ret * a % m;
        a = (u128)a * a % m;
        p /= 2;
    }
    return ret;
}

bool is_composite(u64 n, u64 a, u64 d, ll s){
    u64 x = BigMod(a, d, n);

    if(x == 1 || x == n - 1) return false;

    for(int r = 1; r < s; r++){
        x = (u128)x * x % n;
        if(x == n - 1) return false;
    }

    return true;
}

bool MillerRabin(u64 n){
    if(n == 1) return false;
    if(n % 2 == 0 && n != 2) return false;
    if(n == 2 || n == 3) return true;

    vector<ll> temp = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    int s = 0;
    u64 d = n - 1;
    while(!(d & 1)){
        d /= 2; s++;
    }

    for(auto a : temp){
        if(n % a == 0) return n == a;
        if(is_composite(n, a, d, s)) return false;
    }

    return true;
}
