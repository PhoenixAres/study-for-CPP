#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e6 + 10;
int n, m, t, a[maxn], b[maxn];
 
int main()
{
    scanf("%d%d%d", &n, &m, &t);
    int x = n;
    for (int i = 1; i <= m; ++i) scanf("%d%d", a+i, b+i);
    for (int i = 1; i <= m; ++i)
    {
        n -= a[i] - b[i-1];
        if (n <= 0) { printf("No\n"); return 0; }
        n = min(x, n+b[i]-a[i]);
    }
    n -= t - b[m];
    if (n <= 0) { printf("No\n"); return 0; }
    printf("Yes\n");
    return 0;
}