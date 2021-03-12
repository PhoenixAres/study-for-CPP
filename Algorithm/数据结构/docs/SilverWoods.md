# Silver Woods

原题链接：[Silver Woods](https://atcoder.jp/contests/abc181/tasks/abc181_f)

分析：显然可以二分圆的半径，那么现在问题转化成判断半径为 r 的圆是否能够满足题意。

考虑什么情况下半径为 r 的圆不能通过这些点。尝试用并查集维护一些关系：

如果两个点之间的距离 < 2*r ，那么说明该圆不能从两者之间通过，那么我们在他们两点之间连一条边。

最后维护完并查集，它们之间的连通关系表明：**该圆不能完全通过连通块内的点**。

**如果该题只能从两点之间通过，那么想要满足题意上述连通块的个数必须 = n。**

不过该题可以在边界和点之间通过，那么我们将上下边界看成两个特殊点，考虑每个点与上下边界的关系，如果距离小于 < 2*r ， 一样不能通过，那么我们在他们之间连边。

最后如果上下边界不在一个连通块内，那么说明一定有路径满足题意，如果在一个连通块内，说明不存在路径。

时间复杂度：
$$
O(n^2logn \alpha (n))，其中，n为点的个数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 100 + 10;
int n;
int par[maxn];
int x[maxn], y[maxn];

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

double dist(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

bool check(double r)
{
    // 将上下边界分别看成第n+1和n+2个点
    for (int i = 1; i <= n+2; ++i) par[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        if (100-y[i] < 2*r) par[find(n+1)] = find(i);
        if (y[i]+100 < 2*r) par[find(n+2)] = find(i);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (dist(i, j) < 2*r) par[find(i)] = find(j);
    return find(n+1) == find(n+2);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", x+i, y+i);
    double l = 0;
    double r = 100;
    // 二分浮点数时，指定次数，避免精度问题
    for (int i = 1; i <= 100; ++i)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%f\n", l);
    return 0;
}
```

