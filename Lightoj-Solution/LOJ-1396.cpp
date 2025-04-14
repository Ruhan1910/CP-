#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(n, k) (n | (1LL << k))
#define unset(n, k) (n & ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);

void solve() {
    string s; cin >> s;
    int n = s.size();

    int l = n / 2, r = n / 2;
    if(n % 2 == 0) l--;

    int have_option = 0, flag = 1;
    if((n & 1) && (s[l] != '9')) have_option = 1;

    for(int i = l, j = r; i >= 0; i--, j++){
        if(s[i] < s[j]) break;
        if(s[i] > s[j]){
            flag = 0;
            while(i >= 0) s[j++] = s[i--];
            break;
        }
    }

    if(flag && have_option){
        flag = 0;
        s[l]++;
        l--, r++;
        while(l >= 0) s[r++] = s[l--];
    }

    if(flag){
        for(int i = l, j = r; i >= 0; i--, j++){
            if(s[i] != '9' && flag){
                flag = 0;
                s[i]++;
                s[j] = s[i];

                for(int m = i + 1, n = j - 1; m <= n; m++, n--){
                    s[m] = s[n] = '0';
                }
                for(int m = i - 1, n = j + 1; m >= 0; m--, n++){
                    s[n] = s[m];
                }
                break;
            }
        }
    }

    if(flag){
        cout << 1;
        for(int i = 0; i < n - 1; i++) cout << 0;
        cout << 1 << endl;
        return;
    }

    cout << s << endl;
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
