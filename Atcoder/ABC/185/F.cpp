#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 3e5 + 10;
int tree[maxn];
int a[maxn];
int n, q;
 
int lowbit(int x)
{
    return x & (-x);
}
 
void update(int n, int x)
{
    for (int i = n; i < maxn; i += lowbit(i))
        tree[i] ^= x;
}
 
int query(int n)
{
    int ans = 0;
    for (int i = n; i; i -= lowbit(i))
        ans ^= tree[i];
    return ans;
}
 
int query(int a, int b)
{
    return query(b) ^ query(a-1);
}
 
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i), update(i, a[i]);
    while (q--)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) update(x, y);
        else printf("%d\n", query(x, y));
    }
    return 0;
}