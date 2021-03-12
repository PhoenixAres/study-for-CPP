#include <bits/stdc++.h>
using namespace std;

int a[5][5];

bool IsAd(int x,int y)
{
    for (int i=0;i<5;i++)
    {
        if (a[x][i]>a[x][y]) return false;
        if (a[i][y]<a[x][y]) return false;
    }
    return true;
}

int main()
{
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            cin >> a[i][j];
    bool judge=false;
    int i,j;
    for (i=0;i<5;i++)
    {
        for (j=0;j<5;j++)
            if (IsAd(i,j))
            {
                judge=true;
                break;
            }
        if (judge) break;
    }

    if (judge) cout << i+1 << " " << j+1 << " " << a[i][j] << endl;
    else cout << "not found" << endl;
    return 0;
}