const int N = 1e7 + 10;
bitset<N> MARK;
vector<int> PRIME;

void sieve(){
    MARK[0] = MARK[1] = 1;

    for(int i = 4; i < N; i += 2) MARK[i] = 1;

    for(int i = 3; i * i < N; i += 2){
        if(!MARK[i]){
            for(int j = i * i; j < N; j += (i * 2)){
                MARK[j] = 1;
            }
        }
    }

    PRIME.push_back(2);
    for(int i = 3; i < N; i += 2){
        if(!MARK[i]) PRIME.push_back(i);
    }

    return;
}
