int maxSubArray(vector<int>& nums) {
    int mx = 0, temp = 0;
    for(int i = 0; i < nums.size(); i++){
        temp += nums[i];
        mx = max(mx, temp);
        if(temp < 0) temp = 0;
    }

    return mx;
}
