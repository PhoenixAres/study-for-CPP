#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];
    for (int i=0;i<10;i++)
        cin >> a[i];
    int h;
    cin >> h;
    int cnt=0;
    for (int i=0;i<10;i++)
        if (h+30>=a[i]) cnt++;
    cout << cnt << endl;
    return 0;
}