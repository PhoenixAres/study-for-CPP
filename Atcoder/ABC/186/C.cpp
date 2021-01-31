#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
char s[10];
 
int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        bool flag = true;
        sprintf(s, "%d", i);
        for (int i = 0; s[i]; ++i) if (s[i] == '7') flag = false;
        sprintf(s, "%o", i);
        for (int i = 0; s[i]; ++i) if (s[i] == '7') flag = false;
        if (flag) ++ans;
    }
    cout << ans;
    return 0;
}