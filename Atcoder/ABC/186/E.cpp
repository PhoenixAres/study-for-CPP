#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int t;
ll n, s, k;
 
ll x, y, g;
void exgcd(ll a, ll b)
{
    if (b == 0) x = 1, y = 0, g = a;
    else
    {
        exgcd(b,a%b);
        ll temp = x;
        x = y;
        y = temp - a/b*y;
    }
}
 
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &n, &s, &k);
        ll a, b, c;
        a = k;
        b = n;
        c = n-s;
        exgcd(a, b);
        if (c%g != 0) { printf("-1\n"); continue; }
        x = x*c/g;
        b /= g;
        printf("%lld\n", (x%b+b)%b);
    }
    return 0;
}