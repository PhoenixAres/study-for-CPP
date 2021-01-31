#include <bits/stdc++.h>
using namespace std;

int a[100];
int maxlen[100];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", a + i);
        maxlen[i] = 1;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
        {
            if (a[j] <= a[i])
                maxlen[j] = max(maxlen[j], maxlen[i] + 1);
        }
    cout << *max_element(maxlen + 1, maxlen + n + 1) << endl;
    return 0;
}