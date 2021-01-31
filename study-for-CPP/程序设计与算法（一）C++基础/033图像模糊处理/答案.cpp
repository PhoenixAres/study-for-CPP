#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int a[n][m];
    int b[n][m];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            cin >> a[i][j];
            b[i][j]=a[i][j];
        }
    for (int i=1;i<n-1;i++)
    {
        for (int j=1;j<m-1;j++)
            b[i][j]=floor(0.5+1.0*(a[i][j]+a[i][j-1]+a[i][j+1]+a[i-1][j]+a[i+1][j])/5);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout << b[i][j];
            if (j<m-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}