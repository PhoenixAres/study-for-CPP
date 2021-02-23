#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, s, dep[maxn], maxDep, last;
vector<pair<int, int> > p[maxn];

void dfs(int cur, int d, int pre)
{
    dep[cur] = d;
    if (d > maxDep)
    {
        maxDep = d;
        last = cur;
    }
    for (int i = 0; i < p[cur].size(); ++i)
    {
        int v = p[cur][i].first;
        int w = p[cur][i].second;
        if (v != pre) dfs(v, d+w, cur);
    }
}

int main()
{
    while (scanf("%d%d", &n, &s) != EOF)
    {
        for (int i = 1; i <= n; ++i) p[i].clear();
        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            p[a].push_back(make_pair(b, c));
            p[b].push_back(make_pair(a, c));
            ans += c;
        }
        last = maxDep = -1;
        dfs(s, 0, -1);
        maxDep = -1;
        dfs(last, 0, -1);
        printf("%d\n", ans*2-dep[last]);
    }


    return 0;
}