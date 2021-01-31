#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e3 + 10;
char s[10];
 
int main()
{
    scanf("%s", s);
    if (s[0] == s[1] && s[1] == s[2]) printf("Won\n");
    else printf("Lost\n");
    return 0;
}