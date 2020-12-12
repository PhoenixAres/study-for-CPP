#include <bits/stdc++.h>
using namespace std;

char mp[300][300];
int mark[300][300];
int minL[300][300][20];
int m, n, t;
int minLen;
int tempLen;

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
    if (x - 1 >= 0 && !mark[x-1][y])
    {
        mark[x-1][y] = 1;
        if (mp[x-1][y] == '#')
        {
            if (t)
            {
                --t;
                ++tempLen;
                dfs(x - 1, y);
                --tempLen;
                ++t;
            }
        }
        else
        {
            ++tempLen;
            dfs(x - 1, y);
            --tempLen;
        }
        mark[x-1][y] = 0;
    }
    if (x + 1 < m && !mark[x+1][y])
    {
        mark[x+1][y] = 1;
        if (mp[x+1][y] == '#')
        {
            if (t)
            {
                --t;
                ++tempLen;
                dfs(x + 1, y);
                --tempLen;
                ++t;
            }
        }
        else
        {
            ++tempLen;
            dfs(x + 1, y);
            --tempLen;
        }
        mark[x+1][y] = 0;
    }
    if (y + 1 < n && !mark[x][y+1])
    {
        mark[x][y+1] = 1;
        if (mp[x][y+1] == '#')
        {
            if (t)
            {
                --t;
                ++tempLen;
                dfs(x, y + 1);
                --tempLen;
                ++t;
            }
        }
        else
        {
            ++tempLen;
            dfs(x, y + 1);
            --tempLen;
        }
        mark[x][y+1] = 0;
    }
    if (y - 1 >= 0 && !mark[x][y-1])
    {
        mark[x][y-1] = 1;
        if (mp[x][y-1] == '#')
        {
            if (t)
            {
                --t;
                ++tempLen;
                dfs(x, y - 1);
                --tempLen;
                ++t;
            }
        }
        else
        {
            ++tempLen;
            dfs(x, y - 1);
            --tempLen;
        }
        mark[x][y-1] = 0;
    }
}

int main()
{
    scanf("%d%d%d", &m, &n, &t);
    for (int i = 0; i < m; ++i)
        scanf("%s", mp[i]);
    bool judge = false;
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mp[i][j] == '@')
            {
                x = i;
                y = j;
                judge = true;
                break;
            }
        }
        if (judge) break;
    }

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