#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e3 + 10;
struct f
{
    int id, v;
    bool operator < (const f & a) const
    {
        if (v == a.v) return id < a.id;
        return v > a.v;
    }
} t[maxn];

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &t[i].id, &t[i].v);
    sort(t+1, t+n+1);
    m = floor(m*1.5);
    int i = m+1;
    for (; i <= n; ++i)
        if (t[i].v < t[m].v) break;
    m = i-1;
    printf("%d %d\n", t[m].v, m);
    for (int i = 1; i <= m; ++i) printf("%d %d\n", t[i].id, t[i].v);
    return 0;
}