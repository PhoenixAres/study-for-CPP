#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, m, a[maxn];

bool check(int mid)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] + sum > mid) sum = 0, ++cnt, --i;
        else if (a[i] + sum == mid) sum = 0, ++cnt;
        else
        {
            sum += a[i];
            if (i == n) ++cnt;
        }
    }
    return cnt > m;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    int l = *max_element(a+1, a+n+1);
    int r = 0;
    for (int i = 1; i <= n; ++i) r += a[i];
    int ans = 0x3f3f3f3f;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1, ans = min(ans, mid);
    }
    printf("%d\n", ans);
    return 0;
}