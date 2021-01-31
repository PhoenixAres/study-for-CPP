#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
vector<pair<int, int> > r[maxn];
int n, m;
bool vis[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        r[x].push_back(make_pair(y, z));
        r[y].push_back(make_pair(x, z));
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));
    int cnt = 0;
    int ans = 0;
    while (!pq.empty() && cnt < n)
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += w;
        ++cnt;
        for (int i = 0; i < r[u].size(); ++i)
        {
            int v = r[u][i].first;
            int w = r[u][i].second;
            if (!vis[v]) pq.push(make_pair(w, v));
        }
    }
    if (cnt < n) printf("orz\n");
    else printf("%d\n", ans);
    return 0;
}
