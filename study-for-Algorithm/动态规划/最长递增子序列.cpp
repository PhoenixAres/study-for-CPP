class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] > dp[dp.size() - 1]) dp.emplace_back(nums[i]);
            else *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        return dp.size();
    }
};