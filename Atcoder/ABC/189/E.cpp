#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n, m, q;
 
struct Mat3x1
{
    ll a[4] = {0};
} p[maxn];
 
struct Mat3x3
{
    ll a[4][4] = {0};
} b[maxn];
 
Mat3x3 operator * (const Mat3x3 & x, const Mat3x3 & y)
{
    Mat3x3 t;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            for (int k = 1; k <= 3; ++k) t.a[i][j] += x.a[i][k] * y.a[k][j];
    return t;
 
}
 
Mat3x1 operator * (const Mat3x3 & x, const Mat3x1 & y)
{
    Mat3x1 t;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j) t.a[i] += x.a[i][j] * y.a[j];
    return t;
 
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld%lld", &p[i].a[1], &p[i].a[2]), p[i].a[3] = 1;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int x;
        ll y;
        scanf("%d", &x);
        if (x > 2) scanf("%lld", &y);
        if (x == 1) b[i].a[1][2] = 1, b[i].a[2][1] = -1, b[i].a[3][3] = 1;
        else if (x == 2) b[i].a[1][2] = -1, b[i].a[2][1] = 1, b[i].a[3][3] = 1;
        else if (x == 3) b[i].a[1][1] = -1, b[i].a[1][3] = 2*y, b[i].a[2][2] = 1, b[i].a[3][3] = 1;
        else b[i].a[1][1] = 1, b[i].a[2][2] = -1, b[i].a[2][3] = 2*y, b[i].a[3][3] = 1;
    }
    b[0].a[1][1] = b[0].a[2][2] = b[0].a[3][3] = 1;
    for (int i = 2; i <= m; ++i) b[i] = b[i] * b[i-1];
    scanf("%d", &q);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Mat3x1 t = b[x] * p[y];
        printf("%lld %lld\n", t.a[1], t.a[2]);
    }
    return 0;
}