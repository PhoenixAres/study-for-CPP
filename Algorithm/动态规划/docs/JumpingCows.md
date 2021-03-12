# Jumping Cows

原题链接：[Jumping Cows](http://poj.org/problem?id=2181)

状态：dp [i] [j] 表示到达第 i 个位置且状态为 j 时的能获得最大价值，其中，j 只有两个取值，为1表示喝掉当前魔水可以增加 a[i]，为0表示减少 a[i]

转移方程：依据题意可知，j 需要交替取值，而对于当前魔水可以选择喝或者不喝，那么有如下方程：

- dp [i] [0] = max( dp [i-1] [1] + a[i]，dp [i-1] [0] )
- dp [i] [1] = max( dp [i-1] [0] - a[i]，dp [i-1] [1] )

入口：dp [i] [0] = a[i]，即每个位置能获得的最大价值是喝掉魔水

出口：dp [n] [0]

时间复杂度：
$$
O(n)，其中，n为魔水个数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 150000 + 10;
int p;
int a[maxn];
int dp[maxn][2];

int main()
{
    scanf("%d", &p);
    for (int i = 1; i <= p; ++i) scanf("%d", a+i);
    for (int i = 1; i <= p; ++i) dp[i][0] = a[i];
    for (int i = 1; i <= p; ++i)
    {
        dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0] - a[i], dp[i-1][1]);
    }
    printf("%d\n", dp[p][0]);
    return 0;
}
```



