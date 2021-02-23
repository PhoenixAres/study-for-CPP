#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int dfs(int n, int m)
{
    if (n == 0) return 1;
    int ans = 0;
    for (int i = m; i <= n; ++i) ans += dfs(n-i, i);
    return ans;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) printf("%d\n", dfs(n, 1));
    return 0;
}