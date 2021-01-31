#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int t, n, size[maxn], dp[maxn];
vector<int> p[maxn];

void dfs(int cur, int pre)
{
    size[cur] = 1;
    int maxSize = 0;
    for (int i = 0; i < p[cur].size(); ++i)
    {
        int v = p[cur][i];
        if (v == pre) continue;
        dfs(v, cur);
        size[cur] += size[v];
        maxSize = max(maxSize, size[v]);
    }
    dp[cur] = max(maxSize, n-size[cur]);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) p[i].clear();
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            p[u].push_back(v);
            p[v].push_back(u);
        }
        dfs(1, -1);
        int *m = min_element(dp+1, dp+n+1);
        printf("%d %d\n", m-dp, *m);
    }


    return 0;
}