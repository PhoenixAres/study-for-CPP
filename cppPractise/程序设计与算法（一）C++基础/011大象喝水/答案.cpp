#include <bits/stdc++.h>
using namespace std;

int main()
{
    const double pi=3.14159;
    int h,r,n;
    cin >> h >> r;
    n=1;
    while (h*r*r*pi*n<20000)
        n++;
    cout << n << endl;
    return 0;
}