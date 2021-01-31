#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e3 + 10;
int n, m, s, t;
vector<pair<int, int> > p[maxn];
int v[maxn];
int dis[maxn];


int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        for (int j = 1; j <= c; ++j) scanf("%d", v+j);
        for (int j = 1; j <= c; ++j)
            for (int k = j+1; k <= c; ++k)
            {
                p[v[j]].push_back(make_pair(v[k], a+(k-j)*b));
                p[v[k]].push_back(make_pair(v[j], a+(k-j)*b));
            }
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (w > dis[u]) continue;
        for (int i = 0; i < p[u].size(); ++i)
        {
            int v = p[u][i].first;
            int w = p[u][i].second;
            if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, pq.push(make_pair(dis[v], v));
        }
    }
    if (dis[t] == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", dis[t]);
    return 0;
}