#include <bits/stdc++.h>
using namespace std;

int a[20];

int main()
{
    long long n;
    cin >> n;
    if (n<0)
    {
        n=-n;
        cout << "-";
    }
    int i=0;
    while (n)
    {
        a[i++]=n%10;
        n/=10;
    }
    int j;
    for (j=0;j<i && !a[j];j++);
    for (int k=j;k<i;k++) cout << a[k];
    cout << endl;
    return 0;
}