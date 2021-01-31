#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
char field[110][110];
int n, m;

void dfs(int x, int y)
{
    field[x][y] = '.';
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (x+i >= 0 && x+i < n && y+j >= 0 && y+j < m && field[x+i][y+j] == 'W') dfs(x+i, y+j);
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (field[i][j] == 'W') 
            {
                ++ans;
                dfs(i, j);
            }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", field + i);
    
    solve();
    return 0; 
}