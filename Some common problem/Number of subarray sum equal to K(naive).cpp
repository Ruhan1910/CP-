int subarraySum(vector<int>& nums, int k){
    int n = nums.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j >= 0; j--){
            sum += nums[j];
            if(sum == k) res++;
        }
    }

    return res;
}
