#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e3 + 10;
int n;
int x[maxn];
int y[maxn];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", x+i, y+i);
    int ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
        {
            double k = 1.0*(y[i]-y[j])/(x[i]-x[j]);
            if (k >= -1 && k <= 1) ++ans;
        }
    printf("%d\n", ans);
 
    return 0;
}