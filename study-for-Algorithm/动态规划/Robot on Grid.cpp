#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 3e5 + 10;
int h, w, k;
char s[5010][5010];
ll dp[5010][5010];
const ll m = 998244353;
 
ll ksm(ll a, ll k)
{
    ll r = 1;
    a = a % m;
    for (; k; k >>= 1, a = a*a%m)
        if (k & 1) r = r*a%m;
    return r;
}
 
int main()
{
    scanf("%d%d%d", &h, &w, &k);
    for (int i = 1; i <= k; ++i)
    {
        char ch[5];
        int x, y;
        scanf("%d%d%s", &x, &y, ch);
        s[x][y] = ch[0];
    }
    dp[1][1] = ksm(3, h*w-k);
    ll ans = ksm(3, m-2);
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
        {
            if (s[i][j] == 'R') dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % m;
            else if (s[i][j] == 'D') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % m;
            else if (s[i][j] == 'X')
            {
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % m;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % m;
            }
            else
            {
                dp[i][j+1] = (dp[i][j+1] + dp[i][j] * ans % m) % m;
                dp[i][j+1] = (dp[i][j+1] + dp[i][j] * ans % m) % m;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j] * ans % m) % m;
                dp[i+1][j] = (dp[i+1][j] + dp[i][j] * ans % m) % m;
            }
        }
    printf("%lld\n", dp[h][w]);
    return 0;
}