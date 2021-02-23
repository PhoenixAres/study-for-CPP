#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, m;
char s[510][510];
bool t[510][510];

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
            pair<int, int> x = q.front();
            q.pop();
            if (t[x.first][x.second]) continue;
            t[x.first][x.second] = 1;
            if (x == e) { flag = true; break; }
            else
            {
                if (x.first+1 <= n && !t[x.first+1][x.second] && s[x.first+1][x.second] != '#')
                    q.push(make_pair(x.first+1, x.second));
                if (x.second+1 <= m && !t[x.first][x.second+1] && s[x.first][x.second+1] != '#')
                    q.push(make_pair(x.first, x.second+1));
                if (x.first-1 >= 1 && !t[x.first-1][x.second] && s[x.first-1][x.second] != '#')
                    q.push(make_pair(x.first-1, x.second));
                if (x.second-1 >= 1 && !t[x.first][x.second-1] && s[x.first][x.second-1] != '#')
                    q.push(make_pair(x.first, x.second-1));
            }

        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}