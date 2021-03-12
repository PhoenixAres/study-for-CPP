#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int an,bn,cn;
    an=bn=cn=0;
    while (n--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        an+=a;
        bn+=b;
        cn+=c;
    }
    cout << an << " " << bn << " " << cn << " " << an+bn+cn << endl;
    return 0;
}