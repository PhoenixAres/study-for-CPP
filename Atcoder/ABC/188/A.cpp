#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

int x, y;
 
int main()
{
    cin >> x >> y;
    if (abs(x-y) < 3) cout << "Yes";
    else cout << "No";
 
    return 0;
}