#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e5 + 10;
int n, m;
int BIT[maxn], a[maxn];

int lowbit(int x)
{
    return x & (-x);
}

void update(int s, int x)
{
    for (int i = s; i <= n; i += lowbit(i)) BIT[i] += x;
}

int query(int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += BIT[i];
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    for (int i = 1; i <= n; ++i) update(i, a[i]-a[i-1]);
    while (m--)
    {
        int p, x, y, k;
        scanf("%d%d", &p, &x);
        if (p == 1) scanf("%d%d", &y, &k);
        if (p == 1) update(x, k), update(y+1, -k);
        else printf("%d\n", query(x));
    }
    return 0;
}