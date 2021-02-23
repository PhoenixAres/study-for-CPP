#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e4 + 10;
int n, m, f[maxn];

int find(int x)
{
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}

void merge(int x, int y)
{
    f[find(x)] = find(y);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) f[i] = i;
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1) merge(y, z);
        else
        {
            if (find(y) == find(z)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}