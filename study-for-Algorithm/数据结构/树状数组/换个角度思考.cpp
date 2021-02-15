#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n, m;
int BIT[maxn];
pair<int, int> p[maxn];

int lowbit(int x)
{
    return x & -x;
}

void update(int s, int x)
{
    for (int i = s; i <= n; i += lowbit(i)) BIT[i] += x;
}

int query(int s)
{
    int ans = 0;
    for (int i = s; i; i -= lowbit(i)) ans += BIT[i];
    return ans;
}

struct node
{
    int l, r, x, id;
    bool operator < (const node & a) const
    {
        return x < a.x;
    }
} a[maxn];

int ans[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i].first), p[i].second = i;
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].x), a[i].id = i;
    sort(a + 1, a + m + 1);
    int j = 1;
    for (int i = 1; i <= m; ++i)
    {
        while (j <= n && p[j].first <= a[i].x) update(p[j].second, 1), ++j;
        ans[a[i].id] = query(a[i].r) - query(a[i].l - 1);
    }
    
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}