#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n;
struct node
{
    ll a, b;
    void read()
    {
        scanf("%lld%lld", &a, &b);
    }
    bool operator < (const node & p) const
    {
        return a*2+b > p.a*2+p.b;
    }
} p[maxn];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) p[i].read();
    sort(p+1, p+n+1);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) sum += p[i].a;
    int ans = 0;
    ll k = 0;
    for (int i = 1; i <= n; ++i)
    {
        k += p[i].a + p[i].b;
        sum -= p[i].a;
        ++ ans;
        if (k > sum)
        {
            printf("%d\n", ans);
            return 0;
        }
    }
 
    return 0;
}