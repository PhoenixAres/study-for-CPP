#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
char a[50], b[50], c[50];

void Flip(int n)
{
    if (c[n] == '1') c[n] = '0';
    else c[n] = '1';
    if (c[n+1])
    {
        if (c[n+1] == '1') c[n+1] = '0';
        else c[n+1] = '1';
    }
    if (n)
    {
        if (c[n-1] == '1') c[n-1] = '0';
        else c[n-1] = '1';
    }
}

int main()
{
    scanf("%s%s", a, b);
    if (a[1] == 0)
    {
        if (a[0] == b[0]) printf("%d\n", 0);
        else printf("%d\n", 1);
        return 0;
    }
    memcpy(c, a, sizeof(a));
    int n1, n2;
    n1 = n2 = 0;
    n1 ++;
    Flip(0);
    int i;
    for (i = 1; c[i]; i ++)
    {
        if (c[i-1] != b[i-1])
        {
            Flip(i);
            n1 ++;
        }
    }
    if (c[i-1] != b[i-1]) n1 = -1;
    memcpy(c, a, sizeof(a));
    for (i = 1; c[i]; i ++)
    {
        if (c[i-1] != b[i-1])
        {
            Flip(i);
            n2 ++;
        }
    }
    if (c[i-1] != b[i-1]) n2 = -1;
    if (n1 == -1 && n2 == -1) printf("impossible\n");
    else if (n1 != -1 && n2 == -1) printf("%d\n", n1);
    else if (n1 == -1 && n2 != -1) printf("%d\n", n2);
    else printf("%d\n", min(n1, n2));
    return 0;
}