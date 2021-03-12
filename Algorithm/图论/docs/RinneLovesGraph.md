# Rinne Loves Graph

原题链接：[Rinne Loves Graph](https://ac.nowcoder.com/acm/problem/22594)

分析：最短路问题，考虑 Dijkstra 算法，但会发现题目多了一个状态，即**只能穿过不超过 K 次被戒严的城镇**。

传统的 Dijkstra 算法求的是：dis[i] 表示从起点 s 到其他顶点的最短路。

那么本题可将其扩展成二维（即多一个状态）：**dis[i] [j] 表示从起点 s 在穿过 j 次被戒严的城镇的情况下达其他顶点时的最短路**。

其实这样一扩展，有点 DP 的味道，DP 四部曲如下：

状态：dis[i] [j] 表示从起点 s 在穿过 j 次被戒严的城镇的情况下达其他顶点时的最短路。

转移方程：通过 Dijkstra 算法来进行状态转移

入口：dis[1] [0] = 0，表示起点在 1 号点，此时没有穿过被戒严的城镇，最短路为 0，即还没开始走。

出口：min( dis[n] [i] )，其中，0 <= i <= k

时间复杂度：
$$
O(mklogn)，其中，n为顶点数，m为边数，k为最多穿过戒严的城镇数
$$




```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e3 + 10;
// 扔进堆里的数据结构，比传统Dijkstra多了一个状态k
struct node
{
    int w;
    int v, k;
    node(int a, int b, int c):w(a), v(b), k(c){}
    bool operator < (const node & a) const
    {
        return w > a.w;
    }
};
int n, m, k;
vector<pair<int, int> > p[maxn];
int vis[maxn]; // 标记该城镇是否被戒严
int dis[maxn][20];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", vis+i);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        p[x].push_back(make_pair(y, z));
        p[y].push_back(make_pair(x, z));
    }
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> pq;
    dis[1][0] = 0;
    pq.push(node(0, 1, 0));
    while (!pq.empty())
    {
        node temp = pq.top();
        pq.pop();
        if (dis[temp.v][temp.k] < temp.w) continue;
        for (int i = 0; i < p[temp.v].size(); ++i)
        {
            int v = p[temp.v][i].first;
            int w = p[temp.v][i].second;
            // 松弛操作，针对是否是戒严的城镇分开讨论
            if (vis[temp.v])
            {
                if (temp.k == k) continue;
                if (dis[v][temp.k+1] > dis[temp.v][temp.k] + w)
                    dis[v][temp.k+1] = dis[temp.v][temp.k] + w, pq.push(node(dis[v][temp.k+1], v, temp.k+1));
            }
            else
            {
                if (dis[v][temp.k] > dis[temp.v][temp.k] + w)
                    dis[v][temp.k] = dis[temp.v][temp.k] + w, pq.push(node(dis[v][temp.k], v, temp.k));
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i) ans = min(ans, dis[n][i]);
    if (ans == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
```

