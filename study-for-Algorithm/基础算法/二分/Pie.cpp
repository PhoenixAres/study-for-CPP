#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e4 + 10;
const double pi = acos(-1);
int t, n, f;
double a[maxn];

bool check(double x)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += int(a[i] / x);
    return cnt < f;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &f);
        ++f;
        for (int i = 1; i <= n; ++i) scanf("%lf", a+i), a[i] *= a[i] * pi;
        double l = 0;
        double r = *max_element(a+1, a+n+1);
        for (int i = 1; i <= 100; ++i)
        {
            double mid = l + (r - l) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        printf("%.4f\n", l);
    }

    return 0;
}