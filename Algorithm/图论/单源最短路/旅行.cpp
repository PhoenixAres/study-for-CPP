#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e3 + 10;
int t, n, m, dis[maxn];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        vector<pair<int, int> > p[maxn];
        for (int i = 1; i <= m; ++i)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            p[x].push_back(make_pair(y, z));
            p[y].push_back(make_pair(x, z));
        }
        int ans = -1;
        for (int i = 1; i <= n; ++i)
        {
            memset(dis, 0x3f, sizeof(dis));
            dis[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
            pq.push(make_pair(0, i));
            while (!pq.empty())
            {
                int u = pq.top().second;
                int w = pq.top().first;
                pq.pop();
                if (dis[u] < w) continue;
                for (int j = 0; j < p[u].size(); ++j)
                {
                    int w = p[u][j].second;
                    int v = p[u][j].first;
                    if (dis[v] > w + dis[u]) dis[v] = w + dis[u], pq.push(make_pair(dis[v], v));
                }
            }
            priority_queue<int> p1;
            for (int i = 1; i <= n; ++i) if (dis[i] < 0x3f3f3f3f && dis[i]) p1.push(dis[i]);
            if (p1.size() >= 2)
            {
                int sum = p1.top();
                p1.pop();
                sum += p1.top();
                ans = max(ans, sum);
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}