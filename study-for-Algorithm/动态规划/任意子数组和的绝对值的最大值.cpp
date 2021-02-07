class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
         int ans = 0;
        int s1 = 0;
        int s2 = 0;
        for (auto i : nums)
        {
            s1 += i;
            s2 += i;
            ans = max(ans, abs(s1));
            ans = max(ans, abs(s2));
            s1 = max(0, s1);
            s2 = min(0, s2);
        }
        return ans;
    }
};