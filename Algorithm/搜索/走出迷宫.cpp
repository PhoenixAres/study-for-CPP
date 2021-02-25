#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, m;
char s[510][510];
bool t[510][510];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
        pair<int, int> b, e;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (s[i][j] == 'S') b.first = i, b.second = j;
                else if (s[i][j] == 'E') e.first = i, e.second = j;
        queue<pair<int, int> > q;
        q.push(b);
        bool flag = false;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (t[x][y]) continue;
            t[x][y] = 1;
            if (x == e.first && y == e.second) { flag = true; break; }
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > n) continue;
                if (ny < 1 || ny > m) continue;
                if (!t[nx][ny] && s[nx][ny] != '#') q.push({nx, ny});
            }

        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}