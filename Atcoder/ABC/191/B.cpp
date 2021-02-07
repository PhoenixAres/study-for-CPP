#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e3 + 10;
int n, x;
 
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%d", &t);
        if (t != x)
        {
            printf("%d", t);
            if (i < n) printf(" ");
        }
    }
 
    return 0;
}