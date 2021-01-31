#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e6 + 10;
int n;
ll t, a[100];
vector<ll> v1, v2;
 
int main()
{
    scanf("%d%lld", &n, &t);
    for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
    ll ans = 0;
    for (int i = 0; i < (1<<20); ++i)
    {
        ll sum = 0;
        for (int j = 0; j < 20; ++j) sum += ((i>>j)&1) * a[j+1];
        if (sum <= t) v1.push_back(sum), ans = max(ans, sum);
        sum = 0;
        for (int j = 0; j < 20; ++j) sum += ((i>>j)&1) * a[j+21];
        if (sum <= t) v2.push_back(sum), ans = max(ans, sum);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); ++i)
    {
        int m = upper_bound(v2.begin(), v2.end(), t-v1[i]) - v2.begin();
        if (m) ans = max(ans, v1[i] + v2[m-1]);
    }
    printf("%lld\n", ans);
    return 0;
}