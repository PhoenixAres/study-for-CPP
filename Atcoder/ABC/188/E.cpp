#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n, m;
ll a[maxn];
vector<int> p[maxn];
ll mmax[maxn];
bool vis[maxn];
ll ans = -(1e18);
 
void dfs(int x, int y)
{
    vis[x] = 1;
    if (x != y)
    {
        if (a[x]-a[y] < mmax[x]) return;
        mmax[x] = a[x] - a[y];
        ans = max(ans, a[x]-a[y]);
    }
    for (int i = 0; i < p[x].size(); ++i)
        if (!vis[p[x][i]]) dfs(p[x][i], y);
 
 
}
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x].push_back(y);
    }
    fill(mmax, mmax+maxn, -(1e18));
    for (int i = 1; i <= n; ++i)
    {
        memset(vis, 0, sizeof(vis));
        if (p[i].size()) dfs(i, i);
    }
 
    printf("%lld\n", ans);
    return 0;
}