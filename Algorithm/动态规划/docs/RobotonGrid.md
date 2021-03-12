# Robot on Grid

原题链接：[Robot on Grid](https://atcoder.jp/contests/keyence2021/tasks/keyence2021_c)

状态：dp [i] [j] 表示走到（i，j）处的方案数

转移方程：根据所在位置的不同，有如下情况：

- 所在位置 s [i] [j] == 'D'，则只能向下走，即 dp [i + 1] [j] = ( dp [i+1] [j] + dp [i] [j] ) % m

- 所在位置 s [i] [j] == 'R'，则只能向右走，即 dp [i] [j + 1] = ( dp [i] [j + 1] + dp [i] [j] ) % m

- 所在位置 s [i] [j] == 'X'，则可以向右或向下走：

  （1） dp [i + 1] [j] = ( dp [i+1] [j] + dp [i] [j] ) % m

  （2）dp [i] [j + 1] = ( dp [i] [j + 1] + dp [i] [j] ) % m

- 所在位置 s [i] [j] == ' '，那么此处可以填 'D' 'R' 'X' 三种，就要将上述三种情况全部执行一遍，并且要除以3

  为什么：根据题意，所有 s [i] [j] == ' ' 的地方都可以写'D' 'R' 'X' 三种，一共 3^(h * w - k) 种方案。

  每当我们将一个空白位置填上以后，这个地方就确定了，整个方案数就要除以3。

  而又要进行取模运算，考虑费马小定理，可将除以3转换为乘以3^(m - 2)，其中，m为模数998244353

  我们令 ans = 3^(m - 2)，那么具体要做如下操作：

  （1）dp [i] [j+1] = (dp [i] [j+1] + dp [i] [j] * ans % m) % m;

  （2）dp [i] [j+1] = (dp [i] [j+1] + dp [i] [j] * ans % m) % m;

  （3）dp [i+1] [j] = (dp [i+1] [j] + dp [i] [j] * ans % m) % m;

  （4）dp [i+1] [j] = (dp [i+1] [j] + dp [i] [j] * ans % m) % m;

入口：dp[1] [1] = 3^(h * w - k)

出口：dp[h] [w]

时间复杂度：
$$
O(hw)，其中，h和w为矩阵的长和宽
$$




```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e3 + 10;
int h, w, k;
char s[maxn][maxn];
ll dp[maxn][maxn];
const ll m = 998244353;

// 快速幂
ll ksm(ll a, ll k)
{
    ll r = 1;
    a = a % m;
    for (; k; k >>= 1, a = a*a%m)
        if (k & 1) r = r*a%m;
    return r;
}
 
int main()
{
    scanf("%d%d%d", &h, &w, &k);
    for (int i = 1; i <= k; ++i)
    {
        char ch[5];
        int x, y;
        scanf("%d%d%s", &x, &y, ch);
        s[x][y] = ch[0];
    }
    // 初始条件
    dp[1][1] = ksm(3, h*w-k);
    // 把除以3转换为乘以3的逆
    ll ans = ksm(3, m-2);
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
        {
            if (s[i][j] == 'R') dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % m;
            else if (s[i][j] == 'D') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % m;
            else if (s[i][j] == 'X')
            {
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % m;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % m;
            }
            else
            {
                dp[i][j+1] = (dp[i][j+1] + dp[i][j] * ans % m) % m;
                dp[i][j+1] = (dp[i][j+1] + dp[i][j] * ans % m) % m;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j] * ans % m) % m;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j] * ans % m) % m;
            }
        }
    printf("%lld\n", dp[h][w]);
    return 0;
}
```

