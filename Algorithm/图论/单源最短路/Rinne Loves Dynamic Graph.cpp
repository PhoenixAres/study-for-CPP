#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
struct node
{
    int v;
    double w[3];
    node(int a, double b, double c, double d):v(a)
    {
        w[0] = b;
        w[1] = c;
        w[2] = d;
    }
};

struct node1
{
    double w;
    int v, k;
    node1(double a, int b, int c):w(a), v(b), k(c){}
    bool operator < (const node1 & a) const
    {
        return w > a.w;
    }
};
int n, m;
vector<node> p[maxn];
double dis[maxn][5];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        double z;
        scanf("%d%d%lf", &x, &y, &z);
        p[x].push_back(node(y, z, fabs(1/(1-z)), fabs((z-1)/z)));
        p[y].push_back(node(x, z, fabs(1/(1-z)), fabs((z-1)/z)));
    }
    for (int i = 1; i <= n; ++i) fill(dis[i], dis[i]+3, 1e18);
    dis[1][0] = 0;
    priority_queue<node1> pq;
    pq.push(node1(0, 1, 0));
    while (!pq.empty())
    {
        node1 temp = pq.top();
        pq.pop();
        if (dis[temp.v][temp.k] < temp.w) continue;
        for (int i = 0; i < p[temp.v].size(); ++i)
        {
            int v = p[temp.v][i].v;
            double w = p[temp.v][i].w[temp.k];
            int k = (temp.k+1)%3;
            if (dis[v][k] > dis[temp.v][temp.k] + w)
                dis[v][k] = dis[temp.v][temp.k] + w, pq.push(node1(dis[v][k], v, k));
        }
    }
    double ans = 1e18;
    for (int i = 0; i < 3; ++i) ans = min(ans, dis[n][i]);
    if (ans == 1e18) printf("-1\n");
    else printf("%.3f\n", ans);
    return 0;
}