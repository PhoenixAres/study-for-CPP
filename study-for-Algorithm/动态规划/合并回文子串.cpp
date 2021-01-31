#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 50 + 10;
char a[maxn];
char b[maxn];
int t, n, m;
bool dp[maxn][maxn][maxn][maxn];
 
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%s", a+1, b+1);
        n = strlen(a+1);
        m = strlen(b+1);
        int ans = 0;
        for (int l1 = 0; l1 <= n; ++l1)
            for (int l2 = 0; l2 <= m; ++l2)
                for (int i = 1; i+l1-1 <= n; ++i)
                    for (int k = 1; k+l2-1 <= m; ++k)
                    {
                        int j = i+l1-1;
                        int l = k+l2-1;
                        if (l1+l2 <= 1) dp[i][j][k][l] = 1;
                        else
                        {
                            dp[i][j][k][l] = 0;
                            if (a[i] == a[j]) dp[i][j][k][l] |= dp[i+1][j-1][k][l];
                            if (a[i] == b[l]) dp[i][j][k][l] |= dp[i+1][j][k][l-1];
                            if (a[j] == b[k]) dp[i][j][k][l] |= dp[i][j-1][k+1][l];
                            if (b[k] == b[l]) dp[i][j][k][l] |= dp[i][j][k+1][l-1];
                        }
                        if (dp[i][j][k][l]) ans = max(ans, l1+l2);
                    }
        printf("%d\n", ans);
    }
    return 0;
}