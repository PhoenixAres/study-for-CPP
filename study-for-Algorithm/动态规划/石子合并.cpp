#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e3 + 10;
int n, a[maxn], dp[maxn][maxn];

int main()
{
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) scanf("%d", a+i), a[i] += a[i-1], dp[i][i] = 0;
    for (int len = 2; len <= n; ++len)
        for (int i = 1; i+len-1 <= n; ++i)
        {
            int j = i+len-1;
            for (int k = i; k <= j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[j] - a[i-1]);
        }
    printf("%d\n", dp[1][n]);
    return 0;
}