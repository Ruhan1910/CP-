ll nCr(ll n, ll r){
    ll ret = 1;
    for(ll i = 1; i <= r; i++){
        ret *= (n - i + 1);
        ret /= i;
    }
}
