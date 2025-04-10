const ll N = 105;
ll fact[N], inv[N];
ll mod = 1e9 + 7;

void precal(){
    fact[0] = inv[0] = 1;
    for(ll i = 1; i < N; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv[N - 1] = BigMod(fact[N - 1], mod - 2, mod);
    for(ll i = N - 2; i >= 1; i--){
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }

    //time complexity O(N)

    //Alternative (if we use this then time complexity will be O(N*log(N)))
    //for(ll i = 1; i < N; i++){
    //    inv[i] = BigMod(fact[i], mod - 2, mod);
    //}
}

ll nCr(ll n, ll r){
    ll res = (((fact[n] * inv[r]) % mod) * inv[n - r]) % mod;
    cout << res << endl;
}
