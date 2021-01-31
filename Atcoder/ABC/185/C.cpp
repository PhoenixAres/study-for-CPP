//思路1：C(L-1, 11)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 210;
int n;
ll c[maxn][maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j <= i; ++j)
            if (!j || j == i) c[i][j] = 1;
            else c[i][j] = c[i-1][j] + c[i-1][j-1];
    cout << c[n-1][11] << endl;
    return 0;
}

//思路2：完全背包
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 210;
int n;
ll dp[maxn][maxn];

int main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= 12; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = j; k <= n; ++k)
                dp[i][k] += dp[i-1][k-j];
    cout << dp[12][n];
    return 0;
}