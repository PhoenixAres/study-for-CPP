#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e3 + 10;
int a, b, c, d;
 
int main()
{
    cin >> a >> b >> c >> d;
    if (d >= a*b && d <= a*c) cout << "No";
    else cout << "Yes";
 
    return 0;
}