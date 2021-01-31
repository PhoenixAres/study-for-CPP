#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 10;
int n, a[maxn];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int m = a[i];
        for (int j = i; j <= n; ++j)
        {
            m = min(m, a[j]);
            ans = max(ans, m*(j-i+1));
        }
    }
    printf("%d\n", ans);
    return 0;
}