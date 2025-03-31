int subarraySum(vector<int>& nums, int k){
    map<int, int>mp;
    mp[0] = 1;
    int sum = 0, res = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        int temp = sum - k;
        res += mp[temp];
        mp[sum]++;
    }

    return res;
}
