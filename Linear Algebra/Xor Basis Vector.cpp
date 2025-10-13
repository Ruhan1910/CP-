ll basis[64], sz;

void insertVector(ll mask){
    for(ll i = 0; i < 64; i++){
        if(!(mask & (1LL << i))) continue;

        if(!basis[i]){
            basis[i] = mask;
            sz++;
            return;
        }
        mask ^= basis[i];
    }
}
