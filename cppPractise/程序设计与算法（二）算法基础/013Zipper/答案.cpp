#include <bits/stdc++.h>
using namespace std;

char a[600], b[600], c[600];
int s[300][300];

int main()
{
    int n;
    scanf("%d", &n);
    for (int k = 0; k < n; k ++)
    {
        scanf("%s%s%s", a, b, c);
        memset(s, 0, sizeof(s));
        int la = strlen(a);
        int lb = strlen(b);
        for (int i = 1; i <= la; i ++)
            s[i][0] = (a[i-1] == c[i-1]);
        for (int i = 1; i <= lb; i ++)
            s[0][i] = (b[i-1] == c[i-1]);
        for (int i = 1; i <= la; i ++)
        {
            for (int j = 1; j <= lb; j ++)
            {
                s[i][j] = (a[i-1] == c[i+j-1] && s[i-1][j]) || (b[j-1] == c[j+i-1] && s[i][j-1]);
            }
        }
        if (s[la][lb]) printf("Data set %d: yes\n", k + 1);
        else printf("Data set %d: no\n", k + 1);
    }
    return 0;
}