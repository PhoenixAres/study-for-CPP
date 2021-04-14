# GCDorMIN

原题链接：[GCDorMIN](https://atcoder.jp/contests/abc191/tasks/abc191_f)

分析：考虑使用有关最大公因数的动态规划，需要考虑两个额外问题：

- 本题需要对所给数组做离散化操作
- 本题题意中多了一个取 min 操作，仔细思考，可以知道，由于最终只剩下一个数字，那么如果取 min ，就会留下数组中的最小值，也就是说，**不可能留下比所给数组中最小的数还大的数**。



时间复杂度：
$$
O(n\sqrt{C} + ClogC)，其中，n为数组长度，C为数组中最大值
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 10;
int n;
int a[maxn];
unordered_map<int, int> mp;

int gcd(int x, int y)
{
    int t = x % y;
    while (t)
    {
        x = y;
        y = t;
        t = x % y;
    }
    return y;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    for (int i = 1; i <= 1e5; ++i) mp[i];
    for (int i = 1; i <= n; ++i) if (a[i] > int(1e5)) mp[a[i]];
    int minv = *min_element(a+1, a+n+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j*j <= a[i]; ++j)
            if (a[i] % j == 0)
            {
                if (!mp[j]) mp[j] = a[i];
                else mp[j] = gcd(mp[j], a[i]);
                if (j * j != a[i])
                {
                    int x = a[i] / j;
                    if (!mp[x]) mp[x] = a[i];
                    else mp[x] = gcd(mp[x], a[i]);
                }
            }
    
    int ans = 0;
    for (auto & i : mp)
        if (i.first <= minv && i.first == i.second) ++ans;

    printf("%d\n", ans);
    return 0;
}
```

