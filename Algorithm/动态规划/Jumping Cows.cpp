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