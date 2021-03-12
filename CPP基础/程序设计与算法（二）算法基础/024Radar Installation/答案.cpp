#include <bits/stdc++.h>
using namespace std;

struct island
{
    int x, y;
    double ps, pe;
    bool operator < (const island & a) const
    {
        return ps - a.ps < 1e-8;
    }
};

island is[2000];

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int t = 0;
    while (!(n == 0 && d == 0))
    {
        ++t;
        bool judge = false;
        if (d < 0) judge = true;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &is[i].x, &is[i].y);
            if (d * d - is[i].y * is[i].y >= 0)
            {
                double x = sqrt(d * d - is[i].y * is[i].y);
                is[i].ps = is[i].x - x;
                is[i].pe = is[i].x + x;
            }
            else judge = true;
        }
        getchar();
        if (judge)
        {
            printf("Case %d: -1\n", t);
            scanf("%d%d", &n, &d);
            continue;
        }
        sort(is, is + n);
        int FirstNoCovered = 0;
        int cnt = 0;
        while (FirstNoCovered < n)
        {
            int i;
            for (i = FirstNoCovered + 1; i < n; ++i)
            {
                int j;
                for (j = FirstNoCovered; j < i; ++j)
                    if (is[i].ps - is[j].pe > 1e-8)
                    {
                        ++cnt;
                        FirstNoCovered = i;
                        break;
                    }
                if (j < i) break;
            }
            if (i == n)
            {
                ++cnt;
                break;
            }
        }
        printf("Case %d: %d\n", t, cnt);
        scanf("%d%d", &n, &d);
    }

    return 0;
}