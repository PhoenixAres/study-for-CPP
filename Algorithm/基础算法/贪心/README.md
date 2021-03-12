# 目录

[1. 区间问题](#1-区间问题)

[2. 字典序最小问题](#2-字典序最小问题)

[3. Sarumans Army](#3-Sarumans-Army)

[4. 题目指南](#4-题目指南)

# 贪心

贪心法就是遵循某种规则，不断贪心地选取当前最优策略的算法设计方法。

## 1. 区间问题

例题：[活动安排](https://ac.nowcoder.com/acm/problem/50161)

分析：可以设计出很多种贪心算法，例如：

（1）每次选择开始时间最早的工作

（2）每次选择用时最短的工作

（3）每次选择结束时间最早的工作

对于（1）和（2）都能找出反例，而（3）是正确的，证明如下：

与其他选择方案相比，该算法在选取了相同数量的更早开始的工作时，其最终结束时间不会比其他方案更晚，故不存在选取更多工作的方案。

时间复杂度（主要是排序的复杂度）：
$$
O(nlogn)，其中n为区间个数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1000 + 10;
struct f
{
    int l, r;
    bool operator < (const f & a) const
    {
        return r < a.r;
    }
    void read()
    {
        scanf("%d%d", &l, &r);
    }
} x[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) x[i].read();
    sort(x+1, x+n+1);
    int ans = 1;
    int r = x[1].r;
    for (int i = 2; i <= n; ++i)
        if (x[i].l >= r) ++ans, r = x[i].r;
    printf("%d\n", ans);
    return 0;
}
```

## 2. 字典序最小问题

例题：[Best Cow Line](http://poj.org/problem?id=3617)

分析：考虑如下贪心算法：

- 按照字典序比较 S 和 S 反转后的字符串 T
- 如果 S 较小，就从 S 开头取出一个文字，追加到 T 的末尾
- 如果 T 较小，就从 S 末尾取出一个文字，追加到 T 的末尾
- （如果相同则取哪个都可以）

时间复杂度：
$$
O(n)，其中n为字符串长度
$$



```cpp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
char s[maxn];
int n;

void solve()
{
    //剩余字符串为 S[a], S[a+1], ..., S[b]
    int a = 0, b = n - 1;
    int cnt = 0;
    while (a <= b)
    {
        //将从左起和从右起的字符串比较
        bool left = false;
        for (int i = 0; a+i <= b; ++i)
            if (s[a+i] < s[b-i])
            {
                left = true;
                break;
            }
            else if (s[a+i] > s[b-i])
            {
                left = false;
                break;
            }
        if (left)
        {
            putchar(s[a++]), ++cnt;
            if (cnt == 80) putchar('\n'), cnt = 0;
        }
        else
        {
            putchar(s[b--]), ++cnt;
            if (cnt == 80) putchar('\n'), cnt = 0;
        }
    }

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    solve();
    return 0;
}
```

## 3. Sarumans Army

原题链接：[Saruman's Army](http://poj.org/problem?id=3069)

分析：贪心思想：从最左边的点开始，应给距离为 R 以内的最远的点做上标记。

因为更左的区域没有覆盖的意义，所以应该尽可能覆盖更靠右的点。

时间复杂度（主要是排序的复杂度）：
$$
O(nlogn)，其中n为点的个数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int r, n;
int a[maxn];

int main()
{
    scanf("%d%d", &r, &n);
    while (r != -1 && n != -1)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        sort(a+1, a+n+1);
        int ans = 0;
        int i = 1;
        while (i <= n)
        {
            // s 是没有被覆盖的最左边的点的位置
            int s = a[i++];
            // 一直向右前进直到距 s 的距离大于 R 的点
            while (i <= n && a[i] <= s+r) ++i;
            // p 是新加上标记的点的位置
            int p = a[i-1];
            // 一直向右前进直到距 p 的距离大于 R 的点
            while (i <= n && a[i] <= p+r) ++i;
            ++ans;
        }
        printf("%d\n", ans);
        scanf("%d%d", &r, &n);
    }
    return 0;
}
```

## 4. 题目指南

[活动安排](#1-区间问题)

[Best Cow Line](#2-字典序最小问题)

[Saruman's Army](#3-Sarumans-Army)

[Tian Ji -- The Horse Racing](docs/田忌赛马.md)

[建筑抢修](docs/建筑抢修.md)

