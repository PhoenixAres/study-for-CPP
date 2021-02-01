#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e3 + 10;
int a, b, c;

int main()
{
    cin >> a >> b >> c;
    if (c)
    {
        if (b >= a+1) cout << "Aoki";
        else cout << "Takahashi";
    }
    else
    {
        if (a >= b+1) cout << "Takahashi";
        else cout << "Aoki";
    }

    return 0;
}