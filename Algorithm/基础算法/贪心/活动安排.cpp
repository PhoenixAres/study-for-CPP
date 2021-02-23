#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1000 + 10;
struct f
{
    int l, r;
    bool operator < (const f & a) const
    {
        return r < a.r;
    }
    void read()
    {
        scanf("%d%d", &l, &r);
    }
} x[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) x[i].read();
    sort(x+1, x+n+1);
    int ans = 1;
    int r = x[1].r;
    for (int i = 2; i <= n; ++i)
        if (x[i].l >= r) ++ans, r = x[i].r;
    printf("%d\n", ans);
    return 0;
}