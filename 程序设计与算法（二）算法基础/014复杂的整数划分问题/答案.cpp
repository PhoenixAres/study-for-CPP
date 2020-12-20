#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int dp[maxn];
int DP[100][100];
set<int> st;

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) == 2)
    {
        memset(DP, 0, sizeof(DP));
        DP[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
            {
                DP[i][j] = DP[i-1][j-1];
                if (i >= j) DP[i][j] += DP[i-j][j];
            }
        printf("%d\n", DP[n][k]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = n; j >= 1; --j)
                if (j >= i) dp[j] += dp[j-i];
        printf("%d\n", dp[n]);
        memset(DP, 0, sizeof(DP));
        for (int i = 1; i <= n; ++i)
        {
            DP[i][0] = 1;
            DP[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (i % 2 == 0) DP[i][j] = DP[i-1][j];
                else
                {
                    DP[i][j] = DP[i-2][j];
                    if (j >= i) DP[i][j] += DP[i][j-i];
                }
            }
        printf("%d\n", DP[n][n]);
    }

    return 0;
}