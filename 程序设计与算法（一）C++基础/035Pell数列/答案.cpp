#include <bits/stdc++.h>
using namespace std;

int a[1000000+10];

int main()
{
    a[1]=1;
    a[2]=2;
    for (int i=3;i<=1000000;i++)
        a[i]=(2*a[i-1]+a[i-2])%32767;
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        cout << a[k] << endl;
    }
    return 0;
}