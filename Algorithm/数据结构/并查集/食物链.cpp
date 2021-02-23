#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int f[maxn];
int find(int x)
{
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}
void merge(int x, int y)
{
    f[find(x)] = find(y);
}
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3*n; ++i) f[i] = i;
    int ans = 0;
    while (k--)
    {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n) ++ans;
        else if (d == 2 && x == y) ++ans;
        else
        {
            if (d == 1)
            {
                if (find(x) == find(y+n) || find(x) == find(y+2*n)) { ++ans; continue;}
                merge(x, y);
                merge(x+n, y+n);
                merge(x+2*n, y+2*n);
            }
            else
            {
                if (find(x) == find(y) || find(x) == find(y+2*n)) { ++ans; continue;}
                merge(x, y+n);
                merge(x+n, y+2*n);
                merge(x+2*n, y);
            }

        }
    }
    printf("%d\n", ans);
    return 0;
}