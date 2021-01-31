#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int n, m;
int a[110][110];
 
int main()
{
    scanf("%d%d", &n, &m);
    int x = 101;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]), x = min(x, a[i][j]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans += max(0, a[i][j] - x);
    printf("%d\n", ans);
    return 0;
}