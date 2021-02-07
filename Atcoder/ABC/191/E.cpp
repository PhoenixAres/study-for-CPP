#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e3 + 10;
int n, m;
vector<pair<int, ll> > p[maxn];
ll ans[maxn][maxn];
ll dis[maxn];
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) ans[i][i] = 1e18;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        ll z;
        scanf("%d%d%lld", &x, &y, &z);
        if (x == y) ans[x][x] = min(ans[x][x], z);
        else p[x].push_back({y, z});
 
    }
    for (int i = 1; i <= n; ++i)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
        pq.push({0, i});
        fill(dis, dis + n + 1, 1e18);
        dis[i] = 0;
        while (!pq.empty())
        {
            ll w = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (dis[u] < w) continue;
            for (int j = 0; j < p[u].size(); ++j)
            {
                int v = p[u][j].first;
                ll w = p[u][j].second;
                if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, pq.push({dis[v], v});
            }
        }
        for (int j = 1; j <= n; ++j)
            if (j != i) ans[i][j] = dis[j];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (j != i && ans[i][j] != 1e18 && ans[j][i] != 1e18) ans[i][i] = min(ans[i][i], ans[i][j] + ans[j][i]);
    for (int i = 1; i <= n; ++i)
        if (ans[i][i] == 1e18) printf("-1\n");
        else printf("%lld\n", ans[i][i]);
    return 0;
}