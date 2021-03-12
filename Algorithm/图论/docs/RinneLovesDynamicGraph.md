# Rinne Loves Dynamic Graph

原题链接：[Rinne Loves Dynamic Graph](https://ac.nowcoder.com/acm/problem/22600)

分析：分析题设函数，可以发现函数1/(1-x)是个周期为三的周期函数，那么边权只有 x，1/(x-1)，(x-1)/x 这三种取值。

传统的 Dijkstra 算法求的是：dis[i] 表示从起点 s 到其他顶点的最短路。

那么本题可将其扩展成二维（即多一个状态）：dis[i] [j] 表示从起点 s 在状态 j 时达其他顶点时的最短路。其中，j 只能取 0,1,2 三个值。具体表现如下：

- 当 j = 0 时，此时边权取值为 fabs(x)
- 当 j = 1 时，此时边权取值为 fabs( 1/(x-1) )
- 当 j = 2 时，此时边权取值为 fabs( (x-1)/x )

其实这样一扩展，有点 DP 的味道，DP 四部曲如下：

状态：dis[i] [j] 表示从起点 s 在状态 j 时达其他顶点时的最短路。其中，j 只能取 0,1,2 三个值。

转移方程：通过 Dijkstra 算法来进行状态转移

入口：dis[1] [0] = 0，表示起点在 1 号点，此时状态为 0，即此时边权取 fabs(x)

出口：min( dis[n] [i] )，其中，0 <= i <= 2

时间复杂度：
$$
O(mlogn)，其中，n为顶点数，m为边数
$$




```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
// 记录边的数据结构
struct node
{
    int v;
    double w[3];
    node(int a, double b, double c, double d):v(a)
    {
        w[0] = b;
        w[1] = c;
        w[2] = d;
    }
};

// 扔进堆里的数据结构
struct node1
{
    double w;
    int v, k;
    node1(double a, int b, int c):w(a), v(b), k(c){}
    bool operator < (const node1 & a) const
    {
        return w > a.w;
    }
};
int n, m;
vector<node> p[maxn];
double dis[maxn][5];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        double z;
        scanf("%d%d%lf", &x, &y, &z);
        p[x].push_back(node(y, z, fabs(1/(1-z)), fabs((z-1)/z)));
        p[y].push_back(node(x, z, fabs(1/(1-z)), fabs((z-1)/z)));
    }
    for (int i = 1; i <= n; ++i) fill(dis[i], dis[i]+3, 1e18);
    dis[1][0] = 0;
    priority_queue<node1> pq;
    pq.push(node1(0, 1, 0));
    while (!pq.empty())
    {
        node1 temp = pq.top();
        pq.pop();
        if (dis[temp.v][temp.k] < temp.w) continue;
        for (int i = 0; i < p[temp.v].size(); ++i)
        {
            int v = p[temp.v][i].v;
            double w = p[temp.v][i].w[temp.k];
            int k = (temp.k+1)%3;
            // 注意松弛操作，k每次要做对1做模3加法
            if (dis[v][k] > dis[temp.v][temp.k] + w)
                dis[v][k] = dis[temp.v][temp.k] + w, pq.push(node1(dis[v][k], v, k));
        }
    }
    double ans = 1e18;
    for (int i = 0; i < 3; ++i) ans = min(ans, dis[n][i]);
    if (ans == 1e18) printf("-1\n");
    else printf("%.3f\n", ans);
    return 0;
}
```

