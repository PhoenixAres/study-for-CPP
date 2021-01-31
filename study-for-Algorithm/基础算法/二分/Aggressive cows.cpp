#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, c, a[maxn];

bool check(int mid)
{
    int cnt = 1;
    int now = a[1];
    for (int i = 2; i <= n; ++i)
       if (a[i] - now >= mid) ++cnt, now = a[i];

    return cnt >= c;
}

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    sort(a+1, a+n+1);
    int l = 1;
    int r = a[n] - a[1];
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid + 1, ans = max(ans, mid);
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}