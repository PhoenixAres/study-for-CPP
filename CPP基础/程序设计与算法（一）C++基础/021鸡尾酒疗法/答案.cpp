#include <bits/stdc++.h>
using namespace std;
struct f
{
    int x,y;
    double n;
};

int main()
{
    int n;
    cin >> n;
    f a[n];
    for (int i=0;i<n;i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].n=1.0*a[i].y/a[i].x;
    }
    for (int i=1;i<n;i++)
    {
        if (a[i].n-a[0].n>0.05) cout << "better" << endl;
        else if (a[0].n-a[i].n>0.05) cout << "worse" << endl;
        else cout << "same" << endl;
    }
    return 0;
}