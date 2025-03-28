//Next permutation in O(n) approach. Just finding the next permutation
///[1, 2, 3, 6, 5, 4] next is [1, 2, 4, 3, 5, 6]
//Here the observation is we need to find the rightmost element which is
//lower then it's next element. Let's call it pivot value. We will need to
//Swap the pivot value with with the next element greater then pivot but
//lower among all the right element of pivot. then just swap it with pivot
//value. Next we need to sort the element of right side of pivot. Actually
//We don't need to sort it we just need to reverse it, then they automatically
//will become sorted. (because they are already in decreasing order).

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

void nextPermutation(vector<int> &arr){
    int n = arr.size();

    //Find the pivot index
    int pivot = -1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] < arr[i + 1]){
            pivot = i; break;
        }
    }

    //If it is the last permutation then we need to return the first permutation
    if(pivot == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    //find the element from right that is greater then pivot value
    for(int i = n-1; i > pivot; i--){
        if(arr[i] > arr[pivot]){
            swap(arr[i], arr[pivot]);
            break;
        }
    }
    reverse(arr.begin() + pivot + 1, arr.end());
}

void solve(){
    vector<int>arr;
    for(int i = 1; i <= 3; i++){
        int x; cin >> x;
        arr.push_back(x);
    }

    nextPermutation(arr);

    for(auto it : arr) cout << it << " ";
    cout << endl;
}

int main(){
    fastio;
    iofile();
    int t=1, tc=1;
    //cin>>t;
    while(t--){
        //cout << "Case " << tc++ << ": ";
        solve();
    }

    return 0;
}
