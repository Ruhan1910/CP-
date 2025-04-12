#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

const int N = 1e3 + 5;
vector<int> v(N);
int n, k;

int possible(int x){
    int temp = 0, cnt = 0;
    for(int i = 0; i <= n; i++){
        if(v[i] > x) return 0;
        if((temp + v[i]) > x){
            cnt++;
            temp = 0;
        }
        temp += v[i];
    }
    
    return cnt <= k;
}

void print_result(int x){
    int temp = 0;
    for(int i = 0; i <= n; i++){
        if(temp + v[i] > x){
            cout << temp << endl;
            temp = 0; k--;
        }
        temp += v[i];
        int have = n - i + 1;

        //We need to stay exactly k night. So we need to 
        //print exactyly k + 1 day walking length
        if(have == k + 1){
            cout << temp << endl;
            for(int j = i + 1; j <= n; j++){
                cout << v[j] << endl;
            }
            return;
        }
    }
    if(temp) cout << temp << endl;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        cin >> v[i];
    }

    int l = 1, r = 1e9, res;
    while(l <= r){
        int m = (l + r) / 2;
        if(possible(m)){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    cout << res << endl;

    print_result(res);
}

int main(){
    fastio;
    int t=1, tc=1;
    cin>>t;
    while(t--){
        cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
