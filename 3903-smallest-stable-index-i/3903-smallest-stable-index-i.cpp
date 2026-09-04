class Solution {
public:
    static int firstStableIndex(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<int> suf(n, 0);
        partial_sum(nums.rbegin(), nums.rend(), suf.rbegin(), [](int sum, int x){ return sum=min(sum, x);});
        int xMax=-1;
        for (int i=0; i<n; i++){
            xMax=max(xMax, nums[i]);
            if (xMax-suf[i]<=k) return i;
        }
        return -1;
    }
};