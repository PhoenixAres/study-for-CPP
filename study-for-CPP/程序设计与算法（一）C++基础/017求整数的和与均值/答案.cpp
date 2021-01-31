#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        sum+=x;
    }
    printf("%d %.5f\n",sum,1.0*sum/n);
    return 0;
}