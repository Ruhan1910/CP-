const int N = 1e6 + 10;
bitset<N> MARK;
vector<int>PRIME;

void sieve(){
    for(int i = 3; i * i < N; i += 2){
        if(!MARK[i]){
            for(int j = i*i; j <= N; j += (i * 2)){
                MARK[j]=1;
            }
        }
    }

    PRIME.push_back(2);
    for(int i = 3; i <= N; i += 2){
        if(!MARK[i]) PRIME.push_back(i);
    }

    return;
}

void seg_sieve(int a, int b){
    if(b < 2){
        cout << "There is no prime in this range" << endl;
        return;
    }
    if(a < 2) a = 2;
    int root = sqrt(b);

    for(int i = 0; i != PRIME.size() && PRIME[i] <= root; i++){
        int x = PRIME[i];
        int j = (a + (x - 1)) / x;
        j *= x;
        if(j == x) j += x;
        for(; j <= b; j += x){
            MARK[j - a] = 1;
        }
    }
    int cnt = 0;
    for(int i = a; i <= b; i++){
        if(!MARK[i - a]) cnt++;
    }
    if(!cnt) cout<<"There is no prime in this range."<<endl;
    else{
        for(int i = a; i <= b; i++){
            if(!MARK[i - a]) cout << i << " ";
        }
        cout << endl;
    }
}
