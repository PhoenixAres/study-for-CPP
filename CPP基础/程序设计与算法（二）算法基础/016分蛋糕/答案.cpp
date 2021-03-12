#include <bits/stdc++.h>
using namespace std;

int ways[30][30][30];

int main()
{
    int w, h, m;
    scanf("%d%d%d", &w, &h, &m);
    while (!(w == 0 && h == 0 && m == 0))
    {
        memset(ways, 0, sizeof(ways));
        for (int i = 1; i <= w; ++i)
            for (int j = 1; j <= h; ++j)
                ways[i][j][0] = i * j;
        for (int i = 1; i <= w; ++i)
            for (int j = 1; j <= h; ++j)
                for (int k = 1; k <= m - 1; ++k)
                    if (i * j < k + 1) ways[i][j][k] = 1 << 30;
        for (int i = 1; i <= w; ++i)
        {
            for (int j = 1; j <= h; ++j)
            {
                for (int k = 1; k <= m - 1; ++k)
                {
                    int SV = i * j;
                    for (int b = 1; b <= i - 1; ++b)
                    {
                        int temp = 1 << 30;
                        for (int a = 0; a <= k - 1; ++a)
                            temp = min(temp, max(ways[b][j][a], ways[i-b][j][k-1-a]));
                        SV = min(SV, temp);
                    }
                    int SH = i * j;
                    for (int b = 1; b <= j - 1; ++b)
                    {
                        int temp = 1 << 30;
                        for (int a = 0; a <= k - 1; ++a)
                            temp = min(temp, max(ways[i][b][a], ways[i][j-b][k-1-a]));
                        SH = min(SH, temp);
                    }
                    ways[i][j][k] = min(SV, SH);
                }
            }
        }
        printf("%d\n", ways[w][h][m-1]);
        scanf("%d%d%d", &w, &h, &m);
    }

    return 0;
}