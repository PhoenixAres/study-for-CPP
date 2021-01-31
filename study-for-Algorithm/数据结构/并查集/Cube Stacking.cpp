#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 3e4 + 10;
int m;
int f[maxn];
int h[maxn];
int s[maxn];
int find(int x)
{
    if (f[x] == x) return x;
    int t = f[x];
    f[x] = find(t);
    h[x] += h[t];
    return f[x];
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    f[x] = y;
    h[x] += s[y];
    s[y] += s[x];
}
int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= maxn; ++i) f[i] = i, s[i] = 1;
    while (m--)
    {
        char ch[10];
        int x, y;
        scanf("%s%d", ch, &x);
        if (ch[0] == 'M') scanf("%d", &y), merge(x, y);
        else if (ch[0] == 'C') find(x), printf("%d\n", h[x]);
    }
    return 0;
}