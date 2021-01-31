#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int a[n][m];
    int b[m][n];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
            b[i][j]=a[j][i];
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout << b[i][j];
            if (j<n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}