#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int m;
char a[10][110];
char b[10][110];
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};

void dfsa(int x, int y)
{
    for (int i = 0; i < 8; ++i)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 1 || nx > 4) continue;
        if (ny < 1 || ny > m) continue;
        if (a[nx][ny] == '*') { a[nx][ny] = '.'; dfsa(nx, ny);}
    }

}

int dfsb(int x, int y)
{
    int ans = 1;
    for (int i = 0; i < 8; ++i)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 1 || nx > 4) continue;
        if (ny < 1 || ny > m) continue;
        if (b[nx][ny] == '*') { b[nx][ny] = '.'; ans += dfsb(nx, ny);}
    }
    return ans;
}

int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= 4; ++i) scanf("%s", a[i]+1);
    for (int i = 1; i <= 4; ++i) scanf("%s", b[i]+1);
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == '*') { a[i][j] = '.'; ++cnt1; dfsa(i, j); }
    vector<int> v;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= m; ++j)
            if (b[i][j] == '*')
            {
                b[i][j] = '.';
                ++cnt2;
                int ans = dfsb(i, j);
                v.push_back(ans);
            }
    sort(v.begin(), v.end());
    if (cnt2 < cnt1) printf("-1\n");
    else
    {
        int ans = 0;
        for (int i = cnt1-1; i < v.size(); ++i)
            ans += v[i];
        printf("%d\n", ans);
    }


    return 0;
}