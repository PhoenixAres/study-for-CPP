#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e4 + 10;
int n, m;
vector<vector<int> > v(maxn);
int s, t;
bool a[maxn];
bool b[maxn];
vector<int> c;
bool judge;

void dfs(int x)
{
    if (x == t)
    {
        for (int i = 0; i < c.size(); ++i) b[c[i]] = 1;
        judge = true;
        return ;
    }
    for (int i = 0; i < v[x].size(); ++i)
    {
        int y = v[x][i];
        if (!a[y])
        {
            if (judge) break;
            a[y] = 1;
            c.push_back(y);
            dfs(y);
            c.pop_back();
            a[y] = 0;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= n; ++i)
        if (!b[i])
        {
            c.clear();
            memset(a, 0, sizeof(a));
            judge = false;
            a[i] = 1;
            c.push_back(i);
            dfs(i);
        }
    if (!b[s]) { printf("-1\n"); return 0; }
    memset(a, 0, sizeof(a));
    queue<pair<int, int> > q;
    q.push(make_pair(s, 0));
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        if (a[x.first]) continue;
        a[x.first] = 1;
        if (x.first == t) { printf("%d\n", x.second); return 0; }

        for (int i = 0; i < v[x.first].size(); ++i)
        {
            int y = v[x.first][i];
            if (!a[y])
            {
                bool flag = true;
                for (int j = 0; j < v[y].size(); ++j)
                    if (!b[v[y][j]]) { flag = false; break; }
                if (flag) q.push(make_pair(v[x.first][i], x.second+1));
            }
        }
    }
    printf("-1\n");
    return 0;
}