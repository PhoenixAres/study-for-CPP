#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e6 + 10;
int n, m;
int a[maxn];
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d", a+i);
    sort(a+1, a+m+1);
    a[m+1] = n+1;
    for (int i = m+1; i >= 1; --i) a[i] = a[i] - a[i-1] - 1;
    int k = n;
    for (int i = 1; i <= m+1; ++i) if (a[i]) k = min(k, a[i]);
    int ans = 0;
    for (int i = 1; i <= m+1; ++i) ans += ceil(1.0*a[i]/k);
    printf("%d\n", ans);
 
    return 0;
}