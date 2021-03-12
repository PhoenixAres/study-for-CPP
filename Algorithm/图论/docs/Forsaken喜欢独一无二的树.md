# Forsaken喜欢独一无二的树

原题链接：[Forsaken喜欢独一无二的树](https://ac.nowcoder.com/acm/problem/53074)

分析：首先，我们要知道，最小生成树的权值是唯一的，但最小生成树不是唯一的，为什么会有多个最小生成树，因为**连接两个相同集合的边的边权有可能相同**。

我们考虑 Kruskal 算法，按照边权排序，把那些连接相同集合且边权相等的边只留下一个。

时间复杂度：
$$
O(mlogm)，其中，m为边数
$$
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
// 存储边的数据结构
struct f
{
    int u,v,w;
    bool operator < (const f & a) const
    {
        return  w < a.w;
    }
} p[maxn];
int par[maxn], h[maxn];
int n, m;

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
    for(int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].w);
    // 按照边权排序
    sort(p+1, p+m+1);
    ll ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int l = i;
        int r = i;
        // 找到一段区间，这段区间内的边的边权是相等的
        while (r <= m && p[r].w == p[i].w) ++r;
        // 将这些边权全部加进答案
        for (int j = l; j < r; ++j)
            if (!same(p[j].u, p[j].v)) ans += p[j].w*1LL;

        // 连接相同集合的边需要留下一个
        for (int j = l; j < r; ++j)
            if (!same(p[j].u, p[j].v)) unite(p[j].u, p[j].v), ans -= p[j].w*1LL;

        i = r-1;
    }
    printf("%lld\n", ans);
    return 0;
}
```

