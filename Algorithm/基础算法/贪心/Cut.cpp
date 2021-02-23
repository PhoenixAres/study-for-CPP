#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int n;
ll a[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
    sort(a+1, a+n+1);
    for (int i = n-1; i > 0; --i) a[i] += a[i+1];
    ll sum = 0;
    for (int i = 1; i <= n-1; ++i) sum += a[i];
    printf("%lld\n", sum);
    return 0;
}