#include <bits/stdc++.h>
using namespace std;

char s[20];

int main()
{
    int l,r;
    cin >> l >> r;
    int cnt=0;
    for (int i=l;i<=r;i++)
    {
        sprintf(s,"%d",i);
        for (int j=0;s[j];j++)
            if (s[j]=='2') cnt++;
    }
    cout << cnt << endl;
    return 0;
}