#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, w[maxn], size[maxn], dp[maxn];
vector<int> p[maxn];

void dfs(int cur, int step, int pre)
{
    size[cur] = w[cur];
    for (int i = 0; i < p[cur].size(); ++i)
    {
        int v = p[cur][i];
        if (v == pre) continue;
        dfs(v, step+1, cur);
        size[cur] += size[v];
    }
    dp[1] += w[cur]*step;
}

void DP(int cur, int pre)
{
    for (int i = 0; i < p[cur].size(); ++i)
    {
        int v = p[cur][i];
        if (v == pre) continue;
        dp[v] = dp[cur] + size[1] - 2*size[v];
        DP(v, cur);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int u, v;
        scanf("%d%d%d", w+i, &u, &v);
        if (u) p[u].push_back(i), p[i].push_back(u);
        if (v) p[v].push_back(i), p[i].push_back(v);
    }
    dfs(1, 0, -1);
    DP(1, -1);
    printf("%d\n", *min_element(dp+1, dp+n+1));


    return 0;
}