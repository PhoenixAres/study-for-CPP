#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 4e5 + 10;
int n, a[maxn], b[maxn], f[maxn];
bool vis[maxn];
map<int, int> mp;
 
int find(int x)
{
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}
 
int main()
{
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", a+i, b+i);
        if (!mp[a[i]]) mp[a[i]] = ++tot;
        if (!mp[b[i]]) mp[b[i]] = ++tot;
    }
    for (int i = 1; i <= tot; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        int x = find(mp[a[i]]);
        int y = find(mp[b[i]]);
        if (x == y) vis[x] = 1;
        else
        {
            f[y] = x;
            if (vis[x] || vis[y]) vis[x] = 1, vis[y] = 0;
        }
    }
    int ans = tot;
    for (int i = 1; i <= tot; ++i)
        if (f[i] == i && !vis[i]) --ans;
    printf("%d\n", ans);
 
    return 0;
}