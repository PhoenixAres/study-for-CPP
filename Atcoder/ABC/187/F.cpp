#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int f[20], n, m, t = 1;
vector<int> p[20];
int ans;
 
bool find(int x, int y)
{
    bool f1, f2;
    f1 = f2 = false;
    for (int i = 0; i < p[x].size(); ++i)
        if (p[x][i] == y) f1 = true;
    for (int i = 0; i < p[y].size(); ++i)
        if (p[y][i] == x) f2 = true;
    return f1 && f2;
}
 
void dfs(int x)
{
    set<int> st;
    for (int i = 1; i < x; ++i) st.insert(f[i]);
    if (ans <= st.size()) return;
    if (x == n+1)
    {
        ans = st.size();
        return ;
    }
    for (int i = 1; i <= t; ++i)
    {
        bool flag = true;
        for (int j = 1; j < x; ++j)
        {
            if (f[j] != i) continue;
            if (!find(j, x)) flag = false;
        }
        if (flag)
        {
            f[x] = i;
            dfs(x+1);
        }
    }
    f[x] = ++t;
    dfs(x+1);
    --t;
}
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x].push_back(y);
        p[y].push_back(x);
    }
    ans = n;
    f[1] = t;
    dfs(2);
    printf("%d\n", ans);
 
    return 0;
}