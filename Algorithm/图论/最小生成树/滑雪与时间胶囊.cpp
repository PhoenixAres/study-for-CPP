#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int h[maxn];
struct node
{
    int v, w;
    node(int a, int b):v(a), w(b) {}
    bool operator < (const node & a) const
    {
        if (h[v] == h[a.v]) return w > a.w;
        return h[v] < h[a.v];
    }
};
vector<node> p[maxn];
int n, m;
bool vis[maxn];



int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", h+i);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (h[x] >= h[y]) p[x].push_back(node(y, z));
        if (h[y] >= h[x]) p[y].push_back(node(x, z));
    }
    int cnt = 0;
    ll ans = 0;
    priority_queue<node> pq;
    pq.push(node(1, 0));
    while (!pq.empty() && cnt < n)
    {
        int w = pq.top().w;
        int u = pq.top().v;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += w*1LL;
        ++cnt;
        for (int i = 0; i < p[u].size(); ++i)
        {
            int v = p[u][i].v;
            int w = p[u][i].w;
            if (!vis[v]) pq.push(node(v, w));
        }
    }
    printf("%d %lld\n", cnt, ans);
    return 0;
}