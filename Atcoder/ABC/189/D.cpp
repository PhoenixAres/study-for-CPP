#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e4 + 10;
int n;
ll dp[100][2];
 
int main()
{
    scanf("%d", &n);
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        char s[10];
        scanf("%s", s);
        if (s[0] == 'A')
        {
            dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1];
            dp[i][1] = dp[i-1][1];
        }
        else
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] * 2 + dp[i-1][0];
        }
    }
    printf("%lld\n", dp[n][1]);
    return 0;
}