class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;
        for (int i = 0; i < nums.size(); ++i) rightSum += nums[i];
        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i) leftSum += nums[i-1];
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};