#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e5 + 10;
int n, m, BIT[maxn];

int lowbit(int x)
{
    return x & -x;
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
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        update(i, x);
    }
    while (m--)
    {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1) update(x, y);
        else printf("%d\n", query(y) - query(x-1));
    }
    return 0;
}