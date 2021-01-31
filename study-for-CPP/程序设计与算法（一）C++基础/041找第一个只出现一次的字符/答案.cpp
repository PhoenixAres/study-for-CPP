#include <bits/stdc++.h>
using namespace std;

char s[100000+10];
int cnt[26]={0};

int main()
{
    cin >> s;
    bool judge=true;
    for (int i=0;s[i];i++) cnt[s[i]-'a']++;
    for (int i=0;s[i];i++)
        if (cnt[s[i]-'a']==1)
        {
            cout << s[i] << endl;
            judge=false;
            break;
        }
    if (judge) cout << "no" << endl;
    return 0;
}