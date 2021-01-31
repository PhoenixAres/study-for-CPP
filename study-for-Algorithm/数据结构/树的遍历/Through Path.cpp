#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n, q, a[maxn], b[maxn], dep[maxn];
ll add[maxn];
vector<int> p[maxn];
 
void getDep(int cur, int step, int pre)
{
    dep[cur] = step;
    for (int i = 0; i < p[cur].size(); ++i)
    {
        int v = p[cur][i];
        if (v != pre) getDep(v, step+1, cur);
    }
}
 
void dfs(int cur, ll preSum, int pre)
{
    add[cur] += preSum;
    for (int i = 0; i < p[cur].size(); ++i)
    {
        int v = p[cur][i];
        if (v != pre) dfs(v, add[cur], cur);
    }
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x].push_back(y);
        p[y].push_back(x);
        a[i] = x;
        b[i] = y;
    }
    getDep(1, 1, -1);
    scanf("%d", &q);
    while (q--)
    {
        int t, e;
        ll x;
        scanf("%d%d%lld", &t, &e, &x);
        if (t == 1)
        {
            if (dep[a[e]] < dep[b[e]])
            {
                add[1] += x;
                add[b[e]] -= x;
            }
            else add[a[e]] += x;
        }
        else
        {
            if (dep[b[e]] < dep[a[e]])
            {
                add[1] += x;
                add[a[e]] -= x;
            }
            else add[b[e]] += x;
        }
    }
    dfs(1, 0, -1);
    for (int i = 1; i <= n; ++i) printf("%lld\n", add[i]);
    return 0;
}