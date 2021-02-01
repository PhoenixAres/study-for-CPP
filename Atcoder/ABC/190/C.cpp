#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e5 + 10;
int n, m, k, f[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
 
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d%d", a+i, b+i);
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) scanf("%d%d", c+i, d+i);
    int ans = 0;
    for (int i = 0; i < (1<<16); ++i)
    {
        memset(f, 0, sizeof(f));
        for (int j = 0; j < 16; ++j)
            if ((i>>j) & 1) f[c[j+1]] = 1;
            else f[d[j+1]] = 1;
        int sum = 0;
        for (int i = 1; i <= m; ++i)
            if (f[a[i]] && f[b[i]]) ++sum;
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
 
    return 0;
}