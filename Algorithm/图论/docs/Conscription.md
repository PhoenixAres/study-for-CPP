# Conscription

原题链接：[Conscription](http://poj.org/problem?id=3723)

分析：如果有一对关系 (x, y, d)，表示 x 号女兵和 y 号男兵之间的亲密度为 d，那么招募这两个人的费用为 10000 * 2 - d。

于是我们仿照 Kruskal 算法的思路，将上述关系建图，边权使用亲密度的相反数，那么从边权最小的边开始遍历。

- 每当遇到一对关系，如果双方均被招募，则跳过。

- 否则，将其边权加入答案 ans。（为什么？不妨设男兵未被招募，那么说明这是第一次遇到与他有关的关系对，也就是亲密度的最大值）

那么最终答案即为 10000 * ( n + m ) - ans 。

时间复杂度：
$$
O(rlogr)，其中，r为关系对个数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e4 + 10;
int n, m, r;
// 存储关系对的数据结构
struct node
{
    int x, y, w;
    bool operator < (const node & a) const
    {
        return w < a.w;
    }
} p[maxn];

int par[maxn], h[maxn];
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &r);
        int N = n + m;
        for (int i = 1; i <= r; ++i)
        {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);
            // 建图，边权使用亲密度的相反数
            p[i].w = -p[i].w;
            ++p[i].x;
            ++p[i].y;
            p[i].y += n;
        }
        sort(p + 1, p + r + 1);
        int ans = 0;
        for (int i = 1; i <= N; ++i) par[i] = i;
        for (int i = 1; i <= r; ++i)
        {
            if (same(p[i].x, p[i].y)) continue;
            ans += p[i].w;
            unite(p[i].x, p[i].y);
        }
        printf("%d\n", 10000 * N + ans);
    }

    return 0;
}
```

