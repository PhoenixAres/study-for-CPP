#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e3 + 10;
char a[maxn], b[maxn];
int dp[maxn][maxn];

int main()
{
    while (scanf("%s%s", a+1, b+1) != EOF)
    {
        int alen = strlen(a+1);
        int blen = strlen(b+1);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= alen; ++i)
            for (int j = 1; j <= blen; ++j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        printf("%d\n", dp[alen][blen]);
    }

    return 0;
}