#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 4e5 + 10;
int n;
ll a[maxn], b[maxn];
 
int main()
{
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
    for (int i = 1; i <= n; ++i) scanf("%lld", b+i);
    for (int i = 1; i <= n; ++i) ans += a[i]*b[i];
    if (!ans) cout << "Yes";
    else cout << "No";
 
    return 0;
}