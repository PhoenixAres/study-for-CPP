#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    if (a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    while (a%b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    cout << b << endl;
    return 0;
}