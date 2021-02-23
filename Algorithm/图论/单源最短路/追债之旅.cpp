#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e3 + 10;
struct node
{
    int w;
    int v, k;
    node(int a, int b, int c):w(a), v(b), k(c){}
    bool operator < (const node & a) const
    {
        return w > a.w;
    }
};
int n, m, k;
vector<pair<int, int> > p[maxn];
int a[20];
int dis[maxn][20];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        p[x].push_back(make_pair(y, z));
        p[y].push_back(make_pair(x, z));
    }
    for (int i = 1; i <= k; ++i) scanf("%d", a+i);
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> pq;
    dis[1][0] = 0;
    pq.push(node(0, 1, 0));
    while (!pq.empty())
    {
        node temp = pq.top();
        pq.pop();
        if (dis[temp.v][temp.k] < temp.w) continue;
        for (int i = 0; i < p[temp.v].size(); ++i)
        {
            int v = p[temp.v][i].first;
            int w = p[temp.v][i].second;
            if (temp.k == k) continue;
            if (dis[v][temp.k+1] > dis[temp.v][temp.k] + w + a[temp.k+1])
                dis[v][temp.k+1] = dis[temp.v][temp.k] + w + a[temp.k+1], pq.push(node(dis[v][temp.k+1], v, temp.k+1));
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i) ans = min(ans, dis[n][i]);
    if (ans == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}