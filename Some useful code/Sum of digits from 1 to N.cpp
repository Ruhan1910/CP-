ll power(ll a, ll p){
    ll ret = 1;
    while(p){
        if(p & 1) ret = ret * a;
        a = a * a;
        p /= 2;
    }

    return ret;
}

vector<ll> sum(22);
void precal(){
    sum[0] = 0;
    sum[1] = 45;
    for(ll i = 2; i < 22; i++){
        sum[i] = sum[i - 1] * 10 + 45 * power(10, i - 1);
    }
}

ll sum_of_digits(ll n){
    if(n < 10){
        return n * (n + 1) / 2;
    }

    ll digit = log10(n);
    ll mx = power(10, digit);
    ll msd = n / mx;

    ll ret = 0;
    //suppose digit = 2, 10^2 - 1 = 99, if msd = 3 then
    //3 times 1 - 99 will add in sum, 0 - 99, 100 - 199, 200, 299
    ret += msd * sum[digit]; 

    //Before we only add 0-99 for this case 0 - 99, 100 - 199, 200, 299
    //so we need to add 1 for 100, 2 for 200. how many times they come?
    //1 come mx time and 2 come mx time.
    ret += (msd * (msd - 1) / 2) * mx;

    //suppose n is 328 we only calculted value before 300 now
    //each 28 times 3 will come. so we add this and then take
    //28 seperate
    ret += msd * (1 + n % mx);
    ret += sum_of_digits(n % mx);

    return ret;
}
