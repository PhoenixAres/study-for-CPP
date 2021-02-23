#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 500;
int t;
char a[maxn], b[maxn], c[maxn];
bool s[maxn][maxn];

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        memset(s, 0, sizeof(s));
        scanf("%s%s%s", a+1, b+1, c+1);
        int alen = strlen(a+1);
        int blen = strlen(b+1);
        for (int i = 1; i <= alen; ++i) s[i][0] = a[i] == c[i];
        for (int i = 1; i <= blen; ++i) s[0][i] = b[i] == c[i];
        for (int i = 1; i <= alen; ++i)
            for (int j = 1; j <= blen; ++j)
                s[i][j] = ((a[i] == c[i+j]) && s[i-1][j]) || (b[j] == c[i+j] && s[i][j-1]);
        printf("Data set %d: ", i);
        if (s[alen][blen]) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}