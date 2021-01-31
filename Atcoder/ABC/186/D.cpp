#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n;
ll a[maxn];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
    sort(a+1, a+n+1);
    ll ans = 0;
    for (int i = 2; i <= n; ++i) ans += (i-1)*a[i];
    for (int i = 1; i < n; ++i) ans -= (n-i)*a[i];
    printf("%lld\n", ans);
 
    return 0;
}