#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
vector<pair<int, int> > r[maxn];
int n, m, s, dis[maxn];

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        r[x].push_back(make_pair(y, z));
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    memset(dis, 0x3f, sizeof(dis));
    pq.push(make_pair(0, s));
    dis[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (dis[u] < w) continue;
        for (int i = 0; i < r[u].size(); ++i)
        {
            int v = r[u][i].first;
            int w = r[u][i].second;
            if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, pq.push(make_pair(dis[v], v));
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", dis[i]);
    return 0;
}