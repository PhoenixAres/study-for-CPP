#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int f[maxn];
int b[maxn];
int n, m;

struct F
{
    int u, v;
    int w;
    bool operator < (const F & a) const
    {
        return w > a.w;
    }
} a[maxn];

int find(int x)
{
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
    sort(a+1, a+m+1);
    for (int i = 1; i <= m; ++i)
    {
        if (find(a[i].u) == find(a[i].v))
        {
            printf("%d\n", a[i].w);
            return 0;
        }
        if (!b[a[i].u]) b[a[i].u] = a[i].v;
        else f[find(a[i].v)] = find(b[a[i].u]);

        if (!b[a[i].v]) b[a[i].v] = a[i].u;
        else f[find(a[i].u)] = find(b[a[i].v]);
    }
    printf("0\n");


    return 0;
}