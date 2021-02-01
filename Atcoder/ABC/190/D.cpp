#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e4 + 10;
ll n;
 
int main()
{
    cin >> n;
    n *= 8;
    int ans = 0;
    for (ll i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0 && i % 2 == 0 && n/i%2 == 0)
        {
            ll a = ((i + n/i) / 2 + 1) / 2;
            ll p = (n/i - i) / 2;
            if (4*a - 2 == i + n/i) ++ans;
        }
    }
    cout << ans * 2;
    return 0;
}