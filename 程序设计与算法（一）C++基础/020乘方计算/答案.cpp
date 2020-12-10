#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,n;
    cin >> a >> n;
    int sum=1;
    while (n--)
        sum*=a;
    cout << sum << endl;
    return 0;
}