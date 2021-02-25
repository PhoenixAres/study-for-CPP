#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
char mp[300][300];
int mark[300][300];
int minL[300][300][20];
int m, n, t;
int minLen;
int tempLen;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    if (tempLen >= minLen) return ;
    if (tempLen >= minL[x][y][t]) return ;
    minL[x][y][t] = tempLen;
    if (mp[x][y] == '+')
    {
        minLen = min(minLen, tempLen);
        return ;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m) continue;
        if (ny < 0 || ny >= n) continue;
        if (mark[nx][ny]) continue;
        mark[nx][ny] = 1;
        if (mp[nx][ny] == '#' && t)
        {
            --t;
            ++tempLen;
            dfs(nx, ny);
            --tempLen;
            ++t;
        }
        else if (mp[nx][ny] != '#')
        {
            ++tempLen;
            dfs(nx, ny);
            --tempLen;
        }
        mark[nx][ny] = 0;
    }

}

int main()
{

    scanf("%d%d%d", &m, &n, &t);
    for (int i = 0; i < m; ++i) scanf("%s", mp[i]);
    int x, y;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (mp[i][j] == '@') x = i, y = j;

    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k <= t; ++k)
                minL[i][j][k] = (1 << 30);
    tempLen = 0;
    minLen = 1 << 30;
    mark[x][y] = 1;
    dfs(x, y);
    if (minLen < (1 << 30)) printf("%d\n", minLen);
    else printf("-1\n");
    return 0;
}