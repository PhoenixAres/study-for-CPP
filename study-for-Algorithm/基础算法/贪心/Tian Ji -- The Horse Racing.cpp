#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1000 + 10;
int a[maxn];
int b[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    while (n)
    {
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        for (int i = 0; i < n; ++i) scanf("%d", b + i);
        sort(a, a + n);
        sort(b, b + n);
        int ia, ja, ib, jb;
        ia = ib = 0;
        ja = jb = n - 1;
        int win = 0;
        int lose = 0;
        while (ia <= ja && ib <= jb)
        {
            if (a[ja] > b[jb]) --ja, --jb, ++win;
            else if (a[ia] > b[ib]) ++ia, ++ib, ++win;
            else
            {
                if (a[ia] < b[jb]) ++lose, ++ia, --jb;
                else break;
            }
        }
        printf("%d\n", 200 * (win - lose));
        scanf("%d", &n);
    }
    return 0;
}