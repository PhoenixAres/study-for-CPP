#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int t=0;
    int tm=0;
    while (n--)
    {
        int a,b;
        cin >> a >> b;
        if (a>=90 && a<=140 && b>=60 && b<=90)
            t++;
        else
        {
            if (t>tm) tm=t;
            t=0;
        }
    }
    if (t>tm) tm=t;
    cout << tm << endl;
    return 0;
}