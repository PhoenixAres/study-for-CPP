# Balanced Lineup G

原题链接：[Balanced Lineup G](https://www.luogu.com.cn/problem/P2880)

分析：构建两个 ST 表，分别记录最大值和最小值。

时间复杂度：
$$
O(nlogn)，其中，n为牛的个数
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e4 + 10;
int n, q, f1[maxn][22], f2[maxn][22];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &f1[i][0]);
        f2[i][0] = f1[i][0];
    }
    for (int j = 1; j <= 21; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            f1[i][j] = max(f1[i][j-1], f1[i+(1<<(j-1))][j-1]);
            f2[i][j] = min(f2[i][j-1], f2[i+(1<<(j-1))][j-1]);
        }

    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int s = log2(r - l + 1);
        int ma = max(f1[l][s], f1[r-(1<<s)+1][s]);
        int mi = min(f2[l][s], f2[r-(1<<s)+1][s]);
        printf("%d\n", ma - mi);

    }

    return 0;
}
```

