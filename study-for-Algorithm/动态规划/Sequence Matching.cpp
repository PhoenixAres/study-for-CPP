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
    for (int i = 1; i <= n; ++i) dp[i][0] = i;
    for (int i = 1; i <= m; ++i) dp[0][i] = i;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}