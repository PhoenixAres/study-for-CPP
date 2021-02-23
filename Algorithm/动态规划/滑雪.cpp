#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 500;
int r, c, a[maxn][maxn], dp[maxn][maxn];
struct node
{
    int x, y, h;
    node(int a, int b, int c):x(a), y(b), h(c){}
    bool operator < (const node & p) const
    {
        return h < p.h;
    }
};
vector<node> v;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            scanf("%d", &a[i][j]), dp[i][j] = 1, v.push_back(node(i, j, a[i][j]));
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < 4; ++j)
        {
            int x = v[i].x + dx[j];
            int y = v[i].y + dy[j];
            if (x < 1 || x > r) continue;
            if (y < 1 || y > c) continue;
            if (a[x][y] > v[i].h) dp[x][y] = max(dp[x][y], dp[v[i].x][v[i].y] + 1);
        }
    int ans = 0;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            ans = max(ans, dp[i][j]);
    printf("%d\n", ans);

    return 0;
}