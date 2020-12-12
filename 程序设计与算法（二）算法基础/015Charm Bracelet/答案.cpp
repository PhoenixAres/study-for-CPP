#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int w[maxn], v[maxn], num[maxn];
int dp[maxn];
int V;

void ZeroOnePack(int w, int v)
{
    for (int j = V; j >= w; --j)
        dp[j] = max(dp[j], dp[j-w] + v);
}

void CompletePack(int w, int v)
{
    for (int j = w; j <= V; ++j)
        dp[j] = max(dp[j], dp[j-w] + v);
}

void MultiplePack(int w, int v, int num)
{
    if (w * num >= V)
        CompletePack(w, v);
    else
    {
        int k = 1;
        while (k < num)
        {
            ZeroOnePack(k * w, k * v);
            num -= k;
            k <<= 1;
        }
        ZeroOnePack(num * w, num * v);
    }
}

int main()
{
    int n;
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", w + i, v + i);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
        ZeroOnePack(w[i], v[i]);
    printf("%d\n", dp[V]);
    return 0;
}