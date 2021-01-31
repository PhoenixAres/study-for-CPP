#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 10;
bool t[maxn];
int l, m;

int main()
{
    scanf("%d%d", &l, &m);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = a; i <= b; ++i) t[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= l; ++i)
        if (!t[i]) ++ans;
    printf("%d\n", ans);
    return 0;
}