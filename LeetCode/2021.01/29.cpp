class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int rows = heights.size();
        int columns = heights[0].size();
        int dp[rows][columns];
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                dp[i][j] = 1e7;
        dp[0][0] = 0;
        struct node
        {
            int x, y, dis;
            node(int a, int b, int c):x(a), y(b), dis(c){}
            bool operator < (const node & a) const
            {
                return dis > a.dis;
            }
        };
        priority_queue<node> q;
        q.push(node(0, 0, 0));
        while (!q.empty())
        {
            int i = q.top().x;
            int j = q.top().y;
            int dis = q.top().dis;
            q.pop();
            if (dp[i][j] < dis) continue;
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= rows) continue;
                if (y < 0 || y >= columns) continue;
                if (dp[x][y] > max(dp[i][j], abs(heights[i][j] - heights[x][y]))) 
                {
                    dp[x][y] = max(dp[i][j], abs(heights[i][j] - heights[x][y]));
                    q.push(node(x, y, dp[x][y]));
                    
                }
            }
        }

        return dp[rows-1][columns-1];
    }
};