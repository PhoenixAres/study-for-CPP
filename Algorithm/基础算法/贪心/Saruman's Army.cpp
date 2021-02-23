#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int r, n;
int a[maxn];

int main()
{
    scanf("%d%d", &r, &n);
    while (r != -1 && n != -1)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        sort(a+1, a+n+1);
        int ans = 0;
        int i = 1;
        while (i <= n)
        {
            int s = a[i++];
            while (i <= n && a[i] <= s+r) ++i;
            int p = a[i-1];
            while (i <= n && a[i] <= p+r) ++i;
            ++ans;
        }
        printf("%d\n", ans);
        scanf("%d%d", &r, &n);
    }
    return 0;
}