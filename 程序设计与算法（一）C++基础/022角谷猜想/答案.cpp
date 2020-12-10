#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n!=1)
    {
        if (n%2)
        {
            cout << n << "*3+1=" << n*3+1 << endl;
            n=3*n+1;
        }
        else
        {
            cout << n << "/2=" << n/2 << endl;
            n/=2;
        }
    }
    cout << "End" << endl;
    return 0;
}