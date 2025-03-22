//Here we need to how many ways we can put k rooks into n * n grid so that no two rooks attack each other.
//so for first rook we have n * n ways to place it then for 2nd one we have (n-1) * (n-1) way and so on.
//But in that case we will calculate some extra result as all the rooks are same.

//Now think for 1st rook we have n ways to place it in 1st row. We can wither put it on 1st row or not and so on.
//If we put the 1st rook in the previous row now for the 2nd rook we have n-1 ways to put it on current row. We will 
//Do it for each rook either we put it in current row and move on next row or not put in and move on next row. 
//If we have currently n way to put a rock in ith row then if we put it then for the next rook it will have n-1 
//way to put it into the upcoming row.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 30 + 5;
ll dp[N][N*N];

ll dpkoro(int ith_pos, int rook, ll way){
    if(rook == 0) return 1;
    if(ith_pos == 0) return 0;
    if(dp[ith_pos][rook] != -1) return dp[ith_pos][rook];

    ll way1 = way * dpkoro(ith_pos - 1, rook - 1, way - 1);
    ll way2 = dpkoro(ith_pos - 1, rook, way);

    return dp[ith_pos][rook] = way1 + way2;
}

void solve(){
    ll n, k; cin >> n >> k;
    memset(dp, -1, sizeof(dp));

    cout << dpkoro(n, k, n) << endl;
}

int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
