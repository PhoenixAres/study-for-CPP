#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,x;
    cin >> m >> n >> x;
    x-=ceil(m*1.0/n);
    while (x>=0 && n<=m)
    {
        n+=floor(m*1.0/n);
        x-=ceil(m*1.0/n);
    }
    cout << n << endl;
    return 0;
}