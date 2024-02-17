Problem link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1721&mosmsg=Submission+received+with+ID+29212992

solution:
//First run a sieve and store all prime numbers

void solve(){
    int m, n; cin>>m>>n;
    int ans = 1e9;
    for(auto it:PRIME){
        if(it>m) break;

        if(m%it==0){
            int cnt=0;
            while(m%it==0){
                cnt++; m/=it;
            }

            int exp=0, tmp=it;
            while(tmp<=n){
                exp+=n/tmp;
                tmp*=it;
            }

            ans=min(ans, exp/cnt);
        }
    }

    if(ans==0) cout<<"Impossible to divide"<<endl;
    else cout<<ans<<endl;

}
