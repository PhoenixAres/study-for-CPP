#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;

struct node
{
    int u, v, w;
    void read()
    {
        scanf("%d%d%d", &u, &v, &w);
    }
    bool operator < (const node & a) const
    {
        return w < a.w;
    }
}r[maxn];
int n, m, f[maxn];

int find(int x)
{
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) r[i].read();
    sort(r+1, r+m+1);
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= m && cnt < n-1; ++i)
    {
        int eu = find(r[i].u);
        int ev = find(r[i].v);
        if (eu == ev) continue;
        f[eu] = ev;
        ans += r[i].w;
        ++cnt;
    }
    if (cnt < n-1) printf("orz\n");
    else printf("%d\n", ans);
    return 0;
}
