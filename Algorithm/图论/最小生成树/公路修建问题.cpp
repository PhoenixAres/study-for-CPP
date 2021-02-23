#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e4 + 10;
struct node
{
    int u, v, w1, w2;
    node(int a, int b, int c, int d):u(a), v(b), w1(c), w2(d){}
};

bool cmp1(const node & a, const node & b)
{
    return a.w1 < b.w1;
}

bool cmp2(const node & a, const node & b)
{
    return a.w2 < b.w2;
}
int n, m, k;
vector<node> p;
int f[maxn];

int find(int x)
{
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i < m; ++i)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        p.push_back(node(a, b, c, d));
    }
    for (int i = 1; i <= n; ++i) f[i] = i;
    sort(p.begin(), p.end(), cmp1);
    int i = 0;
    int cnt = 0;
    int ans = 0;
    for (; i < p.size() && cnt < k; ++i)
    {
        int eu = find(p[i].u);
        int ev = find(p[i].v);
        if (eu == ev) continue;
        ans = max(p[i].w1, ans);
        f[eu] = ev;
        ++cnt;
    }
    sort(p.begin()+i, p.end(), cmp2);
    for (; i < p.size() && cnt < n-1; ++i)
    {
        int eu = find(p[i].u);
        int ev = find(p[i].v);
        if (eu == ev) continue;
        ans = max(ans, p[i].w2);
        f[eu] = ev;
        ++cnt;
    }
    printf("%d\n", ans);
    return 0;
}