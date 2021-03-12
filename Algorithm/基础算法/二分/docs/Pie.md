# Pie

原题链接：[Pie](http://poj.org/problem?id=3122)

分析：将蛋糕分成 m + 1份，问每个人分到的蛋糕最大是多少（每个人所分的蛋糕不能拼凑得到）

时间复杂度：
$$
O(nlogn)，其中，n为蛋糕个数
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e4 + 10;
const double pi = acos(-1);
int t, n, f;
double a[maxn];

bool check(double x)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += int(a[i] / x);
    return cnt < f;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &f);
        ++f;
        for (int i = 1; i <= n; ++i) scanf("%lf", a+i), a[i] *= a[i] * pi;
        double l = 0;
        double r = *max_element(a+1, a+n+1);
        for (int i = 1; i <= 100; ++i)
        {
            double mid = l + (r - l) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        printf("%.4f\n", l);
    }

    return 0;
}
```

