#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
char s[maxn];
int n;

void solve()
{
    int a = 0, b = n - 1;
    int cnt = 0;
    while (a <= b)
    {
        bool left = false;
        for (int i = 0; a+i <= b; ++i)
            if (s[a+i] < s[b-i])
            {
                left = true;
                break;
            }
            else if (s[a+i] > s[b-i])
            {
                left = false;
                break;
            }
        if (left)
        {
            putchar(s[a++]), ++cnt;
            if (cnt == 80) putchar('\n'), cnt = 0;
        }
        else
        {
            putchar(s[b--]), ++cnt;
            if (cnt == 80) putchar('\n'), cnt = 0;
        }
    }

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    solve();
    return 0;
}