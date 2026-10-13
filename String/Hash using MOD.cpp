const ll N = 1e6 + 100;
const ll bs = 3797;
const ll MOD = 1000000007;

ll LH[N], RH[N], B[N];

ll Lhash(int l, int r){
    ll ret = LH[r] - (LH[l - 1] * B[r - l + 1]) % MOD;
    ret = (ret + MOD) % MOD;
    return ret;
}

ll Rhash(int l, int r){
    ll ret = RH[l] - (RH[r + 1] * B[r - l + 1]) % MOD;
    ret = (ret + MOD) % MOD;
    return ret;
}

void hash_koro(string &S){
    B[0] = 1;
    for(int i = 1; i < N; i++){
        B[i] = (B[i - 1] * bs) % MOD;
    }

    int sz = (int)S.size();

    LH[0] = 0;
    for(int i = 1; i <= sz; i++){
        LH[i] = ((FH[i - 1] * bs) % MOD + (S[i - 1] - 'a' + 1)) % MOD;
    }

    RH[sz + 1] = 0;
    for(int i = sz; i >= 1; i--){
        RH[i] = ((RH[i + 1] * bs) % MOD + (S[i - 1] - 'a' + 1)) % MOD;
    }
}
