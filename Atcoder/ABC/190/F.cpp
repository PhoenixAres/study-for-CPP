#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 3e5 + 10;
int n, a[maxn], BIT[maxn];

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
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        ++a[i];
        ans += query(n) - query(a[i]);
        update(a[i], 1);
    }
    printf("%lld\n", ans);
    for (int i = 1; i < n; ++i)
    {
        ans -= query(a[i] - 1);
        ans += query(n) - query(a[i]);
        printf("%lld\n", ans);
    }
    return 0;
}