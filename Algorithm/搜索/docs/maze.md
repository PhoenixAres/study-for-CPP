# maze

原题链接：[maze](https://ac.nowcoder.com/acm/problem/15665)

分析：最短路问题，考虑使用BFS，但题目增加了传送门机制，使用传送门将花费 3 个单位时间。

这其实违背了BFS的本意，BFS的本意是每次状态转移选择距离最近（即花费最少）的点转移，但增加条件后，会出现如下情况：

在一个传送门入口位置，无法事先得知是走传送门的花费少，还是不走传送门的花费少。

于是，为了每次选择花费最少的状态进行转移，使用优先队列替代队列，来进行BFS，可以得到答案。

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, m, q;
char s[310][310];
bool visit[310][310];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
struct f
{
    int x, y;
    int t;
    f(int a, int b, int c):x(a), y(b), t(c){}
    bool operator < (const f & a) const
    {
        return  t > a.t;
    }
};
int sx, sy, tx, ty;

int main()
{
    while (scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        memset(visit, 0, sizeof(visit));
        vector<pair<int, int> > p[310][310];
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        while (q--)
        {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            p[x1][y1].push_back(make_pair(x2, y2));
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (s[i][j] == 'S') sx = i, sy = j;
                else if (s[i][j] == 'T') tx = i, ty = j;
        priority_queue<f> que;
        que.push(f(sx, sy, 0));

        int ans = -1;
        while (!que.empty())
        {
            f x = que.top();
            que.pop();
            if (visit[x.x][x.y]) continue;
            visit[x.x][x.y] = 1;
            if (x.x == tx && x.y == ty) { ans = x.t; break; }
            for (int i = 0; i < 4; ++i)
            {
                int nx = x.x+dx[i];
                int ny = x.y+dy[i];
                if (nx < 0 || nx >= n) continue;
                if (ny < 0 || ny >= m) continue;
                if (s[nx][ny] != '#')
                {

                    que.push(f(nx, ny, x.t+1));
                }
            }
            for (int j = 0; j < p[x.x][x.y].size(); ++j)
            {
                int lx = p[x.x][x.y][j].first;
                int ly = p[x.x][x.y][j].second;
                if (lx < 0 || lx >= n) continue;
                if (ly < 0 || ly >= m) continue;
                if (s[lx][ly] != '#')
                    que.push(f(lx, ly, x.t+3));
            }

        }
        printf("%d\n", ans);
    }

    return 0;
}
```



