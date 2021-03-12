# Reversible Cards

原题链接：[Reversible Cards](https://atcoder.jp/contests/arc111/tasks/arc111_b)

分析：一张牌有两面，每一面有一种颜色，求所有牌朝上的一面最多有多少种颜色。

将一种颜色看成一个顶点，同一张牌上的两种颜色连边，这样就转换成了图相关问题。考虑一个连通块，设其内顶点数为 n，会有以下情况：

- 如果该连通块不成环，那么这个连通块对答案的贡献就是 n-1
- 否则，这个连通块的内的所有颜色都可以取到

可以使用并查集求取连通块，注意需要做离散化处理。

时间复杂度：
$$
O(nlogn)，其中，n为牌的数量
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 4e5 + 10;
int n, a[maxn], b[maxn], par[maxn];
bool vis[maxn]; // 标记连通块是否成环
map<int, int> mp; // 使用map进行离散化

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main()
{
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", a+i, b+i);
        if (!mp[a[i]]) mp[a[i]] = ++tot;
        if (!mp[b[i]]) mp[b[i]] = ++tot;
    }
    for (int i = 1; i <= tot; ++i) par[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        int x = find(mp[a[i]]);
        int y = find(mp[b[i]]);
        // 如果成环，标记
        if (x == y) vis[x] = 1;
        else
        {
            par[y] = x;
            // 保证一个连通块只标记一次
            if (vis[x] || vis[y]) vis[x] = 1, vis[y] = 0;
        }
    }
    int ans = tot;
    for (int i = 1; i <= tot; ++i)
        // 如果不成环，那么该连通块内有有1个颜色取不到
        if (par[i] == i && !vis[i]) --ans;
    printf("%d\n", ans);

    return 0;
}
```

