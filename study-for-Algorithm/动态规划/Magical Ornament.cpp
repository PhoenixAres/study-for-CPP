#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, m, k, c[20], dis[20][maxn], f[1<<17][20];
vector<int> p[maxn];
bool vis[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x].push_back(y);
        p[y].push_back(x);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) scanf("%d", c+i);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= k; ++i)
    {
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int> > q;
        q.push({c[i], 0});
        while (!q.empty())
        {
            int u = q.front().first;
            int w = q.front().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            dis[i][u] = min(dis[i][u], w);
            for (int i = 0; i < p[u].size(); ++i)
                if (!vis[p[u][i]]) q.push({p[u][i], w+1});
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < 17; ++i) f[1<<i][i+1] = 1;
    for (int S = 1; S < (1<<17); ++S)
        for (int i = 0; i < k; ++i)
            for (int j = 1; j <= k; ++j)
            {
                if (f[S][i+1] == 0x3f3f3f3f) continue;
                if (!(S>>i & 1) || dis[i+1][c[j]] == 0x3f3f3f3f || S>>(j-1) & 1) continue;
                f[S | (1<<(j-1))][j] = min(f[S | (1<<(j-1))][j], f[S][i+1] + dis[i+1][c[j]]);
            }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= k; ++i) ans = min(ans, f[(1<<k)-1][i]);
    printf("%d\n", ans == 0x3f3f3f3f ? -1:ans);


    return 0;
}