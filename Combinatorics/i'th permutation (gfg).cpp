#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int n, ith;

void ith_permutation(){
    stack<int>st;
    vector<int>res;
    //Subtracting 1 from i'th because the permutation
    //start from 0 in Factoradic method
    int x = ith - 1;

    //Loop to generate the factroid of the array/sequence
    for(int i = 1; i <= n; i++){
        st.push(x % i);
        x /= i;
    }

    //Loop to generate n'th permutation
    for(int i = 0; i < n; i++){
        int pos = st.top(); st.pop();
        res.push_back(v[pos]);

        for(int j = pos; j < n; j++){
            v[j] = v[j + 1];
        }
    }

    for(auto it : res) cout << it << " ";
    cout << endl;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        v.push_back(i + 1);
    }

    cin >> ith;
    ith_permutation();
}
