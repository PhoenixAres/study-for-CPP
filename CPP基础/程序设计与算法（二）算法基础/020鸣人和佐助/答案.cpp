#include <bits/stdc++.h>
using namespace std;

struct ways
{
    int x, y;
    int t;
    int steps;
    ways(int xx, int yy, int tt, int s):x(xx), y(yy), t(tt), steps(s) {}
};

queue<ways> q;
char s[300][300];
int visited[300][300][20];

int main()
{
    int n, m, t;
    scanf("%d%d%d", &m, &n, &t);
    for (int i = 0; i < m; ++i)
        scanf("%s", s[i]);
    int x, y;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == '@')
            {
                x = i;
                y = j;
            }
    ways w(x, y, t, 0);
    q.push(w);
    memset(visited, 0, sizeof(visited));
    visited[w.x][w.y][w.t] = 1;
    while (!q.empty())
    {
        w = q.front();
        if (s[w.x][w.y] == '+')
        {
            cout << w.steps << endl;
            return 0;
        }
        else
        {
            if (w.x - 1 >= 0)
            {
                if (s[w.x-1][w.y] == '#')
                {
                    if (w.t && !visited[w.x-1][w.y][w.t-1])
                    {
                        ways ww(w.x-1, w.y, w.t-1, w.steps+1);
                        q.push(ww);
                        visited[w.x-1][w.y][w.t-1] = 1;
                    }
                }
                else if (!visited[w.x-1][w.y][w.t])
                {
                    ways ww(w.x-1, w.y, w.t, w.steps+1);
                    q.push(ww);
                    visited[w.x-1][w.y][w.t] = 1;
                }
            }
            if (w.y - 1 >= 0)
            {
                if (s[w.x][w.y-1] == '#')
                {
                    if (w.t && !visited[w.x][w.y-1][w.t-1])
                    {
                        ways ww(w.x, w.y-1, w.t-1, w.steps+1);
                        q.push(ww);
                        visited[w.x][w.y-1][w.t-1] = 1;
                    }
                }
                else if (!visited[w.x][w.y-1][w.t])
                {
                    ways ww(w.x, w.y-1, w.t, w.steps+1);
                    q.push(ww);
                    visited[w.x][w.y-1][w.t] = 1;
                }
            }
            if (w.x + 1 < m)
            {
                if (s[w.x+1][w.y] == '#')
                {
                    if (w.t && !visited[w.x+1][w.y][w.t-1])
                    {
                        ways ww(w.x+1, w.y, w.t-1, w.steps+1);
                        q.push(ww);
                        visited[w.x+1][w.y][w.t-1] = 1;
                    }
                }
                else if (!visited[w.x+1][w.y][w.t])
                {
                    ways ww(w.x+1, w.y, w.t, w.steps+1);
                    q.push(ww);
                    visited[w.x+1][w.y][w.t] = 1;
                }
            }
            if (w.y + 1 < n)
            {
                if (s[w.x][w.y+1] == '#')
                {
                    if (w.t && !visited[w.x][w.y+1][w.t-1])
                    {
                        ways ww(w.x, w.y+1, w.t-1, w.steps+1);
                        q.push(ww);
                        visited[w.x][w.y+1][w.t-1] = 1;
                    }
                }
                else if (!visited[w.x][w.y+1][w.t])
                {
                    ways ww(w.x, w.y+1, w.t, w.steps+1);
                    q.push(ww);
                    visited[w.x][w.y+1][w.t] = 1;
                }
            }
        }
        q.pop();
    }
    cout << "-1" << endl;
    return 0;
}
