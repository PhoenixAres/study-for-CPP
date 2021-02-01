#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e3 + 10;
int n, s, d;
 
 
int main()
{
    cin >> n >> s >> d;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a < s && b > d) { cout << "Yes"; return 0; }
    }
    cout << "No";
 
    return 0;
}