#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n, m, k;
bool vis[maxn];
double dp[maxn][2], now[2];
 
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    while (k--)
    {
        int x;
        scanf("%d", &x);
        vis[x] = 1;
    }
    dp[n][0] = dp[n][1] = 0;
    int l, r;
    l = r = n;
    while (l >= 1)
    {
        int i = l - 1;
        if (vis[i]) dp[i][0] = 1, dp[i][1] = 0;
        else dp[i][0] = now[0] / m, dp[i][1] = now[1] / m + 1;
        now[0] += dp[i][0];
        now[1] += dp[i][1];
        l = i;
        if (r - l + 1 > m) now[0] -= dp[r][0], now[1] -= dp[r][1], --r;
    }
    if (fabs(dp[0][0] - 1) < 1e-8) printf("-1\n");
    else printf("%.4f\n", dp[0][1] / (1 - dp[0][0]));
    return 0;
}