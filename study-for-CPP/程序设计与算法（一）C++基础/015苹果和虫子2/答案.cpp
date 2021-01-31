#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    n-=ceil(1.0*y/x);
    if (n<0) cout << 0;
    else cout << n;
    cout << endl;
    return 0;
}