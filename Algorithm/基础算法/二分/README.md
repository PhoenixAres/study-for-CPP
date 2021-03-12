# 目录

[1. 假定一个解并判断是否可行](#1-假定一个解并判断是否可行)

[2. 最大化最小值](#2-最大化最小值)

[3. 01分数规划](#3-01分数规划)

[4. 题目指南](#4-题目指南)



# 二分

二分法不仅可以在有序序列查找值，在求解最优解问题上也十分有用。

## 1. 假定一个解并判断是否可行

例题：[Cable master](http://poj.org/problem?id=1064)

分析：尝试使用二分搜索模型：条件C(x) = 可以得到 K 条长度为 x 的绳子，则问题变成了求满足C(x)条件最大的 x 。

在区间初始化时，只需要使用充分大的数 INF ( > MAXL) 作为上界即可：lb = 0，ub = INF。

由于长度为 L 的绳子最多可以切出 floor(L / x)段长度为 x 的绳子，因此有：

C(x) = ( floor(L / x) 的总和是否大于或等于 K )

时间复杂度：
$$
O(nlogn)，其中，n为绳子个数
$$



```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 10;
int n, k;
double L[maxn];

// 判断是否满足条件
bool C(double x)
{
    int num = 0;
    for (int i = 1; i <= n; ++i) num += int(L[i] / x);
    return num >= k;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lf", L + i);
    double l = 0;
    double r = 1e5;
    // 重复循环，直到解的范围足够小
    for (int i = 1; i <= 100; ++i)
    {
        double mid = (l + r) / 2;
        if (C(mid)) l = mid;
        else r = mid;
    }
    printf("%.2f\n", floor(l * 100) / 100);

    return 0;
}
```

## 2. 最大化最小值

例题：[Aggressive cows](http://poj.org/problem?id=2456)

分析：定义：C(d) = 可以安排牛的位置使得最近的两头牛的距离不小于 d，那么问题就变成了求满足 C(d) 的最大的 d。

另外，最近的间距不小于 d 也可以说成是所有牛的间距都不小于 d，因此有：

C(d) = 可以安排牛的位置使得任意的牛的间距都不小于 d。

这个问题的判断使用贪心法便可以非常容易求解：

- 对牛舍的位置 x 进行排序
- 把第一头牛放入x_0 的牛舍
- 如果第 i 头牛放入了 x_j 的话，第 i+1 头牛就要放入满足 x_j + d <= x_k 的最小的 x_k 中

时间复杂度：
$$
O(nlogn)，其中，n为牛舍个数
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, c, a[maxn];

bool check(int mid)
{
    int cnt = 1;
    int now = a[1];
    for (int i = 2; i <= n; ++i)
       if (a[i] - now >= mid) ++cnt, now = a[i];

    return cnt >= c;
}

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    sort(a+1, a+n+1);
    int l = 1;
    int r = a[n] - a[1];
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid + 1, ans = max(ans, mid);
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
```

## 3. 01分数规划

这是一类最大化平均值的问题，我们定义：条件C(x) = 可以选择使得单位重量的价值不小于 x，那么原问题变成了求满足C(x)的最大的 x。

如何判断C(x)是否可行？假设我们选了某个物品的集合 S，那么它们的单位重量的价值是：
$$
\sum_{i \epsilon S}{v_i} / \sum_{i \epsilon S}{w_i}
$$
因此就变成了判断是否存在 S 满足下面的条件：
$$
\sum_{i \epsilon S}{v_i} / \sum_{i \epsilon S}{w_i} \geqslant x
$$
把这个不等式进行变形就可以得到：
$$
\sum_{i \epsilon S}{(v_i - x \times w_i)} \geqslant 0
$$
因此，就变成了：
$$
C(x) = ((v_i - x \times w_i)从大到小排列中的前k个的和不小于0)
$$
例题：[Dropping tests](http://poj.org/problem?id=2976)

分析：01分数规划问题，时间复杂度：
$$
O(nlogn)，其中，n为数组长度
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e3 + 10;
int n, k;
double c[maxn], a[maxn], b[maxn];

bool check(double mid)
{
    for (int i = 1; i <= n; ++i) c[i] = a[i] - mid * b[i];
    // 排序，从大到小选k个
    sort(c+1, c+n+1, greater<double>());
    double sum = 0;
    for (int i = 1; i <= n-k; ++i) sum += c[i];
    return sum > 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    while (n || k)
    {
        for (int i = 1; i <= n; ++i) scanf("%lf", a+i);
        for (int i = 1; i <= n; ++i) scanf("%lf", b+i);
        double l = 0;
        double r = 1;
        for (int i = 1; i <= 100; ++i)
        {
            double mid = l + (r - l) / 2;
            if (check(mid)) l = mid;
            else r = mid;
        }
        printf("%.0f\n", l * 100);
        scanf("%d%d", &n, &k);
    }

    return 0;
}
```



## 4. 题目指南 

### 二分搜索

- [Cable master](#1-假定一个解并判断是否可行)

- [Aggressive cows](#2-最大化最小值)

- [Pie](docs/Pie.md)

- [月度开销](docs/月度开销.md)

- [路标设置](docs/路标设置.md)

### 01分数规划

- [Dropping tests](#3-01分数规划)

