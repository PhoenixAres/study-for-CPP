#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

char a[5], b[5];
 
int main()
{
    scanf("%s%s", a, b);
    int sum = 0;
    for (int i = 0; a[i]; ++i) sum += a[i]-'0';
    int ans = sum;
    sum = 0;
    for (int i = 0; b[i]; ++i) sum += b[i]-'0';
    ans = max(ans, sum);
    printf("%d\n", ans);
    return 0;
}