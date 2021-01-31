#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,n;
    cin >> l >> n;
    char x[l+10];
    for (int i=0;i<=l;i++)
        x[i]=1;
    while (n--)
    {
        int a,b;
        cin >> a >> b;
        for (int i=a;i<=b;i++)
            x[i]=0;
    }
    int cnt=0;
    for (int i=0;i<=l;i++)
        if (x[i]) cnt++;
    cout << cnt << endl;
    return 0;
}