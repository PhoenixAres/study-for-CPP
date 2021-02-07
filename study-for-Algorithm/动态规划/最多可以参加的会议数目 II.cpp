class Solution {
public:

    static bool cmp(const vector<int> & a, const vector<int> & b)
    {
        return a[1] < b[1];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);
        vector<vector<int> > dp(n+1, vector<int>(k + 1, 0));
        dp[1][1] = events[0][2];
        for (int i = 1; i < n; ++i)
        {
            int l = 0;
            int r = i;
            int m = -1;
            while (l <= r)
            {
                int mid = l + (r - l)/2;
                if (events[mid][1] >= events[i][0]) r = mid - 1;
                else l = mid + 1, m = max(m, mid);
            }
        
            for (int j = 1; j <= k; ++j)
                dp[i+1][j] = max(dp[i][j], dp[m+1][j-1] + events[i][2]);
        }
        int ans = 0;
        for (int i = 1; i <= k; ++i) ans = max(ans, dp[n][i]);
        return ans;
    }
};