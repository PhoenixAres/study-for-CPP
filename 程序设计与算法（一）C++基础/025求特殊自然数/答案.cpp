#include <bits/stdc++.h>
using namespace std;

int a[5];
int b[5];

int main()
{
    int t;
    for (int i=81;i<=6+6*7+6*49;i++)
    {
        int j=0;
        t=i;
        while (i)
        {
            a[j++]=i%7;
            i/=7;
        }
        j=0;
        i=t;
        while (i)
        {
            b[j++]=i%9;
            i/=9;
        }
        i=t;
        int judge=1;
        for (j=0;j<3;j++)
            if (a[j]!=b[2-j]) judge=0;
        if (judge) break;
    }
    cout << t << endl;
    for (int i=2;i>=0;i--) cout << a[i];
    cout << endl;
    for (int i=2;i>=0;i--) cout << b[i];
    cout << endl;
    return 0;
}