#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e5 + 10;
int n, BIT[maxn], a[maxn];
struct node
{
    int v, id;
    bool operator < (const node & a) const
    {
        if (v == a.v) return id < a.id;
        return v < a.v;
    }
} b[maxn];

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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i].v), b[i].id = i;
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i) a[b[i].id] = i;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += query(n) - query(a[i]);
        update(a[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}