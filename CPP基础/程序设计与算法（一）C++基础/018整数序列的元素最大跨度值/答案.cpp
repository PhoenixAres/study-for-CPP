#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxnum=-1;
    int minnum=2000;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if (x>maxnum) maxnum=x;
        if (x<minnum) minnum=x;
    }
    cout << maxnum-minnum << endl;
    return 0;
}