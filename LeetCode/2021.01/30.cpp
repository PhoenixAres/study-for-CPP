class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int dp[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                dp[i][j] = n*n;
        dp[0][0] = grid[0][0];
        struct node
        {
            int x, y, w;
            node(int a, int b, int c):x(a), y(b), w(c){}
            bool operator < (const node & p) const
            {
                return w > p.w;
            }
        };
        priority_queue<node> q;
        q.push(node(0, 0, 0));
        while (!q.empty())
        {
            int x = q.top().x;
            int y = q.top().y;
            int w = q.top().w;
            q.pop();
            if (dp[x][y] < w) continue;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n) continue;
                if (ny < 0 || ny >= n) continue;
                if (dp[nx][ny] > max(dp[x][y], grid[nx][ny])) 
                {
                    dp[nx][ny] = max(dp[x][y], grid[nx][ny]);
                    q.push(node(nx, ny, dp[nx][ny]));
                }
            }
        }
        return dp[n-1][n-1];
    }
};