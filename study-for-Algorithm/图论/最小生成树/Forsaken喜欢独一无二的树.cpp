#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
struct f
{
    int u,v,w;
    bool operator < (const f & a) const
    {
        return  w < a.w;
    }
} p[maxn];
int f[maxn];
int n, m;

int find(int x)
{
    while(x != f[x]) x = f[x] = f[f[x]];
    return x;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].w);
    sort(p+1, p+m+1);
    ll ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int l = i;
        int r = i;
        while (r <= m && p[r].w == p[i].w) ++r;
        for (int j = l; j < r; ++j)
        {
            int eu = find(p[j].u);
            int ev = find(p[j].v);
            if (eu != ev) ans += p[j].w*1LL;
        }
        for (int j = l; j < r; ++j)
        {
            int eu = find(p[j].u);
            int ev = find(p[j].v);
            if (eu != ev) f[eu] = ev, ans -= p[j].w*1LL;
        }
        i = r-1;
    }
    printf("%lld\n", ans);
    return 0;
}