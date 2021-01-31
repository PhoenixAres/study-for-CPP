#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

 
const int maxn = 1e6 + 10;
int a[4];
 
int main()
{
    for (int i = 0; i < 4; ++i) cin >> a[i];
    cout << *min_element(a, a+4) << endl;
 
    return 0;
}