# 目录

[1. 单源最短路](#1-单源最短路)

- [1.1 BellmanFord算法](#11-BellmanFord算法)
- [1.2 Dijkstra算法](#12-Dijkstra算法)

[2. 全源最短路](#2-全源最短路)

[3. 最小生成树](#3-最小生成树)

- [3.1 Prim算法](#31-Prim算法)
- [3.2 Kruskal算法](#32-Kruskal算法)

[4. 题目指南](#4-题目指南)



# 图论

## 1. 单源最短路

### 1.1 BellmanFord算法

记从起点 s 出发到顶点 i 的最短距离 d[i]，则有下述等式成立：
$$
d[i] = min\{d[j] + (从j到i的边的权值) | e=(j,i) \epsilon E\}
$$
如果给定的图是一个DAG，就可以按拓扑序给顶点编号，并利用这条递推关系式计算出 d。

如果图中有圈，就无法依赖这样的顺序进行计算。在这种情况下，记当前到顶点 i 的最短路长度为 d[i]，并设初值 d[s] = 0，d[i] = INF （足够大的常数），再不断利用这条递推关系式更新 d 的值，就可以算出新的 d。只要图中不存在负圈，这样的更新操作就是有限的。

```cpp
// 从顶点from指向顶点to的权值为cost的边
struct edge { int from, to, cost; };
edge es[max_e]; // 边
int d[max_v];   // 最短距离
int V, E;       // V是顶点数，E是边数

// 求解从顶点s出发到所有点的最短距离
void shortest_path(int s)
{
    for (int i = 0; i < V; ++i) d[i] = INF;
    d[s] = 0;
    while (true)
    {
        bool update = false;
        for (int i = 0; i < E; ++i)
        {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}
```

这个算法称为 Bellman-Ford 算法。如果图中不存在从 s 可达的负圈，那么最短路不会经过同一个顶点两次（也就是说，最多通过|V|-1条边）。

因此复杂度为：
$$
O(|V| \times |E|)
$$
反之，如果存在从 s 可达的负圈，那么第  |V| 次循环中也会更新 d 的值，因此可以利用这个性质来检查负圈。

如果一开始对所有的顶点 i，都将 d[i] 初始化为 0，那么可以检查出所有的负圈。

```cpp
// 如果返回true则存在负圈
bool find_negative_loop()
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < E; ++j)
        {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                // 如果第V次仍然更新了，则存在负圈
                if (i == V-1) return true;
            }
        }
    return false;
}
```



例题：[Layout](http://poj.org/problem?id=3169)

分析：记第 i 号牛的位置是 d[i]，首先，牛是按照编号顺序排列的，所以有 **d[i] <= d[i+1]** 成立。

其次，对于每对关系好的牛之间的最大距离限制，都有 **d[AL] + DL >= d[BL]**，同样，对于每对关系不好的牛，都有 **d[AD] + DD >= d[BD]**。

这些不等式的特点是所有的式子的两边都只出现了1个变量，实际上，图上的最短路问题也可以用这样的形式表示出来。

记从起点 s 出发，到各个顶点 v 的最短距离为 d(v)。因此，**对于每条权值为 w 的边 e = (v, u)，都有 d(v) + w >= d(u) 成立**。

反之，在满足全部这些约束不等式的 d 中，**d(v) - d(s)的最大值就是从 s 到 v 的最短距离**。

那么可以将题目转化为最短路问题，首先将顶点编号为 1~ N。d[i] <= d[i+1] 变形为 d[i+1] + 0 >= d[i]，因此从顶点 i + 1向顶点 i 连一条权值为 0 的边。

同样地，d[AL] + DL >= d[BL] 对应从顶点 AL 向顶点 BL 连一条权值为 DL 的边，d[AD] + DD <= d[BD] 对应从顶点 BD 向顶点 AD 连一条权值为 -DD的边。

所求问题是 d[N] - d[1] 的最大值，由于图中存在负权边，因此不能用 Dijkstra 算法，而使用 Bellman-Ford算法。

时间复杂度：
$$
O(N(N+ML+MD))
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 10;
int N, ML, MD;
int AL[maxn], BL[maxn], DL[maxn];
int AD[maxn], BD[maxn], DD[maxn];
int d[maxn]; // 最短距离
bool updated; // 是否有更新
int INF = 0x3f3f3f3f;

void update(int & x, int y)
{
    if (x > y)
    {
        x = y;
        updated = true;
    }
}

// 用Bellman-Ford算法计算d
void bellmanford()
{
    for (int k = 0; k <= N; ++k)
    {
        updated = false;
        // 从i+1到i的权值为0
        for (int i = 0; i + 1 < N; ++i)
            if (d[i+1] < INF) update(d[i], d[i+1]);
        // 从AL到BL的权值为DL
        for (int i = 0; i < ML; ++i)
            if (d[AL[i] - 1] < INF) update(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
        // 从BD到AD的权值为-DD
        for (int i = 0; i < MD; ++i)
            if (d[BD[i] - 1] < INF) update(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);

    }
}


int main()
{

    scanf("%d%d%d", &N, &ML, &MD);
    for (int i = 0; i < ML; ++i) scanf("%d%d%d", AL + i, BL + i, DL + i);
    for (int i = 0; i < MD; ++i) scanf("%d%d%d", AD + i, BD + i, DD + i);
    // 检查是否存在负圈
    fill(d, d + N, 0);
    bellmanford();
    if (updated)
    {
        printf("-1\n");
        return 0;
    }
    fill(d, d + N, INF);
    d[0] = 0;
    bellmanford();
    int ans = d[N-1];
    if (ans == INF) ans = -2;
    printf("%d\n", ans);
    
    return 0;
}
```



### 1.2 Dijkstra算法

考虑没有负边的情况，在 Bellman-Ford 算法中，如果 d[i] 还不是最短距离的话，那么即使进行 d[j] = d[i] + (从 i 到 j 的边的权值) 的更新，d[j] 也不会变成最短距离。而且，即使 d[i] 没有变化，每一次循环也要检查一遍从 i 出发的所有边，这显然是浪费时间的，因此，可以做如下修改：

（1）找到最短距离已经确定的顶点，从它出发更新相邻顶点的最短距离

（2）此后，不需要关心（1）中最短距离已经确定的顶点

在最开始，只有起点的最短距离是确定的，而在尚未使用过的顶点中，距离 d[i] 最小的顶点就是最短距离已经确定的顶点，这是因为不存在负边，所以 d[i] 不会在之后的更新中变小。

使用堆优化实现该算法，那么时间复杂度变为：
$$
O(|E| log |V|)
$$

```cpp
struct edge { int to, cost; }
typedef pair<int, int> P; // first是最短距离，second是顶点的编号

int V;
vector<edge> G[max_v];
int d[max_v];

void dijkstra(int s)
{
    // 通过指定greater<P>参数，堆按照first从小到大的顺序取出值
    priority_queue<P, vector<P>, greater<P> > que;
    fill (d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
```



例题：[Roadblocks](http://poj.org/problem?id=3255)

分析：Dijkstra算法的思想是依次确定尚未确定的顶点中距离最小的顶点，按照这个思路对算法进行少许修改，就可以求出次短路。

到某个顶点 v 的次短路要么是**到其他某个顶点 u 的最短路再加上 u->v 的边**，要么是**到 u 的次短路再加上 u->v 的边**，因此就是要求出到所有顶点的最短路和次短路，那么对于每个顶点，不仅仅记录最短距离，还有次短距离。

时间复杂度：
$$
O(r logn)
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e3 + 10;
vector<pair<int, int> > p[maxn]; // 图的邻接表表示
int n, r;
int dist[maxn]; // 最短距离
int dist2[maxn]; // 次短距离

int main()
{
    scanf("%d%d", &n, &r);
    while (r--)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        p[x].push_back({y, w});
        p[y].push_back({x, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    memset(dist, 0x3f, sizeof(dist));
    memset(dist2, 0x3f, sizeof(dist2));
    dist[0] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (dist2[u] < d) continue;
        for (int i = 0; i < p[u].size(); ++i)
        {
            int v = p[u][i].first;
            int w = p[u][i].second;
            int d2 = d + w;
            if (dist[v] > d2)
            {
                swap(dist[v], d2);
                pq.push({dist[v], v});
            }
            if (dist2[v] > d2 && dist[v] < d2)
            {
                dist2[v] = d2;
                pq.push({dist2[v], v});
            }
        }
    }
    printf("%d\n", dist2[n]);
    return 0;
}
```

## 2. 全源最短路

可以尝试用DP来求解任意两点间的最短路问题，只使用顶点 0 ~ k 和 i，j 的情况下，记 i 到 j 的最短路长度为 d[k+1] [i] [j]。

当 k = -1时，认为只使用 i 和 j，所以 d[0] [i] [j] = cost [i] [j]，只使用 0~k时，有如下情况：

- 不经过顶点 k，d[k] [i] [j] = d[k-1] [i] [j]
- 经过顶点 k，dp[k] [i] [j] = d[k-1] [i] [k] + d[k-1] [k] [j]

于是有 dp[k] [i] [j] = min( d[k-1] [i] [j]，d[k-1] [i] [k] + d[k-1] [k] [j] )，这个DP也可以使用同一个数组，即 **d[i] [j] = min( dp[i] [j]，dp[i] [k] + dp[k] [j])**

这个算法叫做 Floyd-Warshall 算法，可以处理边是负数的情况，如果要判断图中是否有负圈，只需检查是否存在 d[i] [i] 是负数的顶点 i 就可以了。

时间复杂度：
$$
O({|V|}^3)
$$

```cpp
int d[max_v][max_v]; // d[u][v]表示边e=(u,v)的权值(不存在时设为INF，不过d[i][i] = 0)
int V; // 顶点数

void warshall_floyd()
{
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                d[i][j] = min(dp[i][j], d[i][k] + d[k][j]);
}
```

## 3. 最小生成树

给定一个无向图，如果它的某个子图中任意两个顶点都互相连通并且是一棵树，那么这棵树称为生成树( Spanning Tree )，如果边上有权值，那么使得边权和最小的生成树叫做最小生成树( MST，Minimum Spanning Tree)。

假设有这样一个图：把顶点看作村庄，边看作计划要修建的道路。为了在所有的村庄间通行，恰好修建村庄数目-1条道路时的情形就对应了一棵生成树。修建道路需要投入建设费，那么使得道路建设费用最小的生成树就是最小生成树。

例题：[最小生成树板子](https://www.luogu.com.cn/problem/P3366)

### 3.1 Prim算法

思想：类似 Dijkstra 算法，都是从某个顶点出发，不断添加边的算法。

首先，我们假设一棵只包含一个顶点 v 的树 T，然后贪心地选取 T 和其他顶点之间相连的最小权值的边，并把他加到 T 中，不断进行这个操作，就可以得到最小生成树。

朴素的 Prim 算法时间复杂度：
$$
O({|V|}^2)
$$
堆优化的 Prim 算法时间复杂度：
$$
O(|E|log|V|)
$$

可以发现，朴素的 Prim 算法适用于稠密图，而堆优化的 Prim 算法利用空间换时间，在任何情况下都有满意的时间复杂度，但是空间占用极大。

以下代码是堆优化的 Prim 算法：

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
vector<pair<int, int> > r[maxn]; // 图的邻接表表示
int n, m;
bool vis[maxn]; // 标记每个点是否已经被加入生成树中

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        r[x].push_back(make_pair(y, z));
        r[y].push_back(make_pair(x, z));
    }
    // 堆优化
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));
    int cnt = 0;
    int ans = 0;
    // cnt表示已经加入生成树的顶点个数，当其等于n时退出循环
    while (!pq.empty() && cnt < n)
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += w;
        ++cnt;
        for (int i = 0; i < r[u].size(); ++i)
        {
            int v = r[u][i].first;
            int w = r[u][i].second;
            if (!vis[v]) pq.push(make_pair(w, v));
        }
    }
    // 如果退出循环时，加入生成树的顶点个数小于n，说明图不连通
    if (cnt < n) printf("orz\n");
    else printf("%d\n", ans);
    return 0;
}

```

### 3.2 Kruskal算法

思想：按照边的权值从小到大查看一遍，如果不产生圈（重边也算在内），就把当前这条边加入到生成树中。可以利用并查集判圈。

时间复杂度：
$$
O(|E|log|E|)
$$

可以发现，Kruskal算法相比于 Prim 算法，更适用于稀疏图。

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;

// 存储边的信息，并且重载小于号
struct node
{
    int u, v, w;
    void read()
    {
        scanf("%d%d%d", &u, &v, &w);
    }
    bool operator < (const node & a) const
    {
        return w < a.w;
    }
}r[maxn];
int n, m, par[maxn], h[maxn];

// 并查集
int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (h[x] < h[y]) par[x] = y;
    else
    {
        par[y] = x;
        if (h[x] == h[y]) ++h[x];
    }

}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    scanf("%d%d", &n, &m);
    // 并查集的初始化
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1; i <= m; ++i) r[i].read();
    // 对边进行排序
    sort(r+1, r+m+1);
    int cnt = 0;
    int ans = 0;
    // cnt表示已经加入生成树的边数，我们知道生成树的边数为n-1
    // 如果已经加入了n-1条边，就退出循环
    for (int i = 1; i <= m && cnt < n-1; ++i)
    {
        // 判圈
        if (same(r[i].u, r[i].v)) continue;
        unite(r[i].u, r[i].v);
        ans += r[i].w;
        ++cnt;
    }
    // 如果边数小于n-1，则图不连通
    if (cnt < n-1) printf("orz\n");
    else printf("%d\n", ans);
    return 0;
}
```



## 4. 题目指南

### BellmanFord算法

- [Layout](#11-BellmanFord算法)

### Dijkstra算法

- [Roadblocks](#12-Dijkstra算法)

- [旅行](docs/旅行.md)

- [追债之旅](docs/追债之旅.md)

- [Rinne Loves Graph](docs/RinneLovesGraph.md)

- [Rinne Loves Dynamic Graph](docs/RinneLovesDynamicGraph.md)

### Prim算法

- [滑雪与时间胶囊](docs/滑雪与时间胶囊.md)

### Kruskal算法

- [Conscription](docs/Conscription.md)

- [公路修建问题](docs/公路修建问题.md)

- [Forsaken喜欢独一无二的树](docs/Forsaken喜欢独一无二的树.md)

