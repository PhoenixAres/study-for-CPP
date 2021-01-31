#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int w[maxn], v[maxn];
int dp[maxn];
int V;

int main()
{
    int n;
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", w + i, v + i);
    for (int i = 1; i <= n; ++i)
        for (int j = V; j >= w[i]; --j)
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    printf("%d\n", dp[V]);
    return 0;
}