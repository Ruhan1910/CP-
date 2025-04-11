const int N = 100;
ll nCr[N][N];
void precal(){
    nCr[0][0] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j > i) nCr[i][j] = 0;
            else if(i == j || j == 0) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MOD;
        }
    }
}
