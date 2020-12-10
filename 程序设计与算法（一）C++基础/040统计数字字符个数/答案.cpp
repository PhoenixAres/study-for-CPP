#include <bits/stdc++.h>
using namespace std;

char s[300];

int main()
{
    fgets(s,300,stdin);
    int cnt=0;
    for (int i=0;s[i];i++)
        if (isdigit(s[i])) cnt++;
    cout << cnt << endl;
    return 0;
}