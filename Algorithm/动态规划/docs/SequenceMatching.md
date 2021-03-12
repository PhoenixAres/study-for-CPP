# Sequence Matching

原题链接：[Sequence Matching](https://atcoder.jp/contests/abc185/tasks/abc185_e)

分析：题意大意为，给定两个数组 a，b，从 a，b中分别删去若干个数，使得它们长度相同。

定义 x 为 a 和 b 中删去的元素个数，y 为删除操作结束后，a 和 b 中对应位置的值不相同数目，要求 x + y 的最小值。

状态：dp [i] [j] 表示数组 a 前 i 个数字和数组 b 中前 j 个数字完成上述操作后 x + y 的最小值

转移方程：对于两个数 a[i] 和 b[j]，有如下情况：

- 如果 a[i] == b[j]

  （1）将这两个数都留下来，不会对 x + y 的值作出贡献，即 dp [i] [j] = dp [i-1] [j-1]

  （2）将这两个数都删去，则贡献 + 2，即 dp [i] [j] = dp [i-1] [j-1] + 2，而我们要求最小值，于是在种情况下不如将它们都留下来

  （3）将 a[i] 删去，则贡献 + 1，即 dp [i] [j] = dp [i-1] [j] + 1

  （4）将 b[j] 删去，则贡献 + 1，即 dp [i] [j] = dp [i] [j-1] + 1

- 如果 a[i] != b[j]

  （1）将这两个数都留下来，则贡献 + 1，即 dp [i] [j] = dp [i-1] [j-1] + 1

  （2）将这两个数都删去，则贡献 + 2 - 1，总贡献也为 + 1，即 dp [i] [j] = dp [i-1] [j-1] + 1

  （3）将 a[i] 删去，则贡献 + 1，即 dp [i] [j] = dp [i-1] [j] + 1

  （4）将 b[j] 删去，则贡献 + 1，即 dp [i] [j] = dp [i] [j-1] + 1

- 综上所述，在每次转移中，dp [i] [j] 将会取上述贡献中的最小值

入口：dp [i] [0] = dp [0] [i] = i，即将数全部删去

出口：dp [n] [m]

时间复杂度：
$$
O(nm)，其中，n和m为数组a，b的长度
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1000 + 10;
int n, m, a[maxn], b[maxn];
int dp[maxn][maxn];
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    for (int i = 1; i <= m; ++i) scanf("%d", b+i);
    memset(dp, 0x3f, sizeof(dp));
    // 初始化
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int i = 0; i <= m; ++i) dp[0][i] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            // 状态转移
            if (a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}
```

