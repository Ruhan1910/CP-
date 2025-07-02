int numOfSubarrays(vector<int>& arr){
    int mod = 1e9 + 7;
    map<int, int>mp; 
    mp[0] = 1;
    int sum = 0, res = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        sum %= 2;
        int temp = sum ^ 1;
        res += mp[temp];
        res %= mod;
        mp[sum]++;
    }

    return res;
}
