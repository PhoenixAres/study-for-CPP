#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 

const int maxn = 2e3 + 10;
int h, w;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char p[maxn][maxn];
bool vis[maxn][maxn];
vector<pair<int, int> > v[30];
bool t[30];
struct node
{
    int x, y, step;
    node(int a, int b, int c):x(a), y(b), step(c) {}
};
 
 
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; ++i) scanf("%s", p[i]+1);
    int x, y;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            if (p[i][j] == 'S') x = i, y = j;
            else if (p[i][j] >= 'a' && p[i][j] <= 'z') v[p[i][j]-'a'].push_back(make_pair(i, j));
    queue<node> q;
    q.push(node(x, y, 0));
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        if (p[x][y] == 'G') { printf("%d\n", step); return 0; }
        for (int i = 0; i < 4; ++i)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx < 1 || nx > h) continue;
            if (ny < 1 || ny > w) continue;
            if (!vis[nx][ny] && p[nx][ny] != '#') q.push(node(nx, ny, step+1));
        }
        if (p[x][y] >= 'a' && p[x][y] <= 'z')
        {
            if (t[p[x][y]-'a']) continue;
            t[p[x][y]-'a'] = 1;
            for (int i = 0; i < v[p[x][y]-'a'].size(); ++i)
            {
                int nx = v[p[x][y]-'a'][i].first;
                int ny = v[p[x][y]-'a'][i].second;
                if (!vis[nx][ny]) q.push(node(nx, ny, step+1));
            }
        }
    }
    printf("-1\n");
    return 0;
}