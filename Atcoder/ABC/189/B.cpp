#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e3 + 10;
int n, x;
 
int main()
{
    scanf("%d%d", &n, &x);
    x *= 100;
    for (int i = 1; i <= n; ++i)
    {
        int v, p;
        scanf("%d%d", &v, &p);
        if (v*p > x) { printf("%d\n", i); return 0; }
        x -= v*p;
    }
    printf("-1\n");
    return 0;
}