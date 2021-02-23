#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e3 + 10;
int n, k;
double c[maxn], a[maxn], b[maxn];

bool check(double mid)
{
    for (int i = 1; i <= n; ++i) c[i] = a[i] - mid * b[i];
    sort(c+1, c+n+1, greater<double>());
    double sum = 0;
    for (int i = 1; i <= n-k; ++i) sum += c[i];
    return sum > 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    while (n || k)
    {
        for (int i = 1; i <= n; ++i) scanf("%lf", a+i);
        for (int i = 1; i <= n; ++i) scanf("%lf", b+i);
        double l = 0;
        double r = 1;
        for (int i = 1; i <= 100; ++i)
        {
            double mid = l + (r - l) / 2;
            if (check(mid)) l = mid;
            else r = mid;
        }
        printf("%.0f\n", l * 100);
        scanf("%d%d", &n, &k);
    }

    return 0;
}