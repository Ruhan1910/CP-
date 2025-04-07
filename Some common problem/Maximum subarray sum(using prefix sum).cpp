int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int>pre(n);
    for(int i = 0; i < n; i++){
        pre[i] = nums[i];
        if(i > 0) pre[i] += pre[i - 1];
    }

    int mn = 0, mx = -1e9;
    for(int i = 0; i < n; i++){
        mx = max(mx, pre[i] - mn);
        mn = min(mn, pre[i]);
    }

    return mx;
}
