const ll bs=3797;
const ll MOD=1000000007;
string S;
ll FH[N], RH[N], B[N];

ll Fhash(int l, int r){
    ll ret = FH[r]-(FH[l-1]*B[r-l+1])%MOD;
    if(ret<0) ret+=MOD;
    ret%=MOD;
    return ret;
}

ll Rhash(int l, int r){
    ll ret = RH[l]-(RH[r+1]*B[r-l+1])%MOD;
    if(ret<0) ret+=MOD;
    ret%=MOD;
    return ret;
}

void hash_koro(){
    B[0]=1;
    for(int i=1; i<N; i++) B[i]=(B[i-1]*bs)%MOD;

    cin>>S;
    int sz=S.size();

    FH[0]=0;
    for(int i=1; i<=sz; i++) FH[i]=((FH[i-1]*bs)%MOD+(S[i-1]-'a'+1))%MOD;

    RH[sz+1]=0;
    for(int i=sz; i>=1; i--) RH[i]=((RH[i+1]*bs)%MOD+(S[i-1]-'a'+1))%MOD;
}
