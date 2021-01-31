#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int L, n;
int x[maxn];

void solve()
{
    int minT = 0;
    for (int i = 0; i < n; ++i)
        minT = max(minT, min(x[i], L - x[i]));

    int maxT = 0;
    for (int i = 0; i < n; ++i)
        maxT = max(maxT, max(x[i], L - x[i]));

    printf("%d %d\n", minT, maxT);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &L, &n);
        for (int i = 0; i < n; ++i) scanf("%d", x + i);
        solve();
    }

    return 0;
}