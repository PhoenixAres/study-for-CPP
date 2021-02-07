class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> v1, v2;
        unordered_set<int> s1;
        set<int> s2;
        for (int i = 0; i < n/2; ++i) v1.emplace_back(nums[i]);
        for (int i = n/2; i < n; ++i) v2.emplace_back(nums[i]);
        
        int k = v1.size();
        for (int i = 0; i < (1 << k); ++i)
        {
            int sum = 0;
            for (int j = 0; j < k; ++j)
                if ((i >> j) & 1) sum += v1[j];
            s1.insert(sum);
        }
        k = v2.size();
        for (int i = 0; i < (1 << k); ++i)
        {
            int sum = 0;
            for (int j = 0; j < k; ++j)
                if ((i >> j) & 1) sum += v2[j];
            s2.insert(sum);
        }
        
        int ans = 1e9;
        for (auto i : s1)
        {
            auto p = s2.lower_bound(goal - i); 
            if (p != s2.end()) ans = min(ans, abs(*p + i - goal));
            if (p != s2.begin())
            {
                --p;
                ans = min(ans, abs(*p + i - goal));
            }
        }
        return ans;
    }
};