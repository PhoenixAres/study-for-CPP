#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int t;
int f[maxn];
int n, m, c;
int a[maxn];
int b[maxn];
int dp[maxn];

int find(int x)
{
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &c);
        for (int i = 1; i <= n; ++i) f[i] = i;
        for (int i = 2; i <= n; ++i) scanf("%d%d", a+i, b+i);
        while (m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            f[find(x)] = find(y);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i <= n; ++i)
            if (find(1) == find(i))
                for (int j = c; j >= 0; --j)
                    if (j >= a[i]) dp[j] = max(dp[j], dp[j-a[i]]+b[i]);
        printf("%d\n", dp[c]);
    }
    
    return 0;
}