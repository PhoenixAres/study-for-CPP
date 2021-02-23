#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
char s[30][30];
int t[30][30];

int ways(int i, int j, int w, int h)
{
    if (s[i][j] != '.') return 0;
    int num = 1;
    t[i][j] = 1;
    if (i - 1 >= 0 && !t[i-1][j])
        num += ways(i - 1, j, w, h);
    if (i + 1 < h && !t[i+1][j])
        num += ways(i + 1, j, w, h);
    if (j - 1 >= 0 && !t[i][j-1])
        num += ways(i, j - 1, w, h);
    if (j + 1 < w && !t[i][j+1])
        num += ways(i, j + 1, w, h);
    return num;
}

int main()
{
    int w, h;
    scanf("%d%d", &w, &h);
    while (!(w == 0 && h == 0))
    {
        memset(t, 0, sizeof(t));
        for (int i = 0; i < h; i ++) scanf("%s", s[i]);
        int i, j;
        bool judge = false;
        for (i = 0; i < h; i ++)
        {
            for (j = 0; j < w; j ++)
                if (s[i][j] == '@')
                {
                    judge = true;
                    break;
                }
            if (judge) break;
        }
        s[i][j] = '.';
        printf("%d\n", ways(i, j, w, h));
        scanf("%d%d", &w, &h);
    }
    return 0;
}