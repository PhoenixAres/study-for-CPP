#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string s;
set<string> s1, s2;
 
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        if (s[0] == '!') s1.insert(s);
        else s2.insert(s);
    }
    set<string>::iterator it;
    for (it = s1.begin(); it != s1.end(); ++it)
        if (s2.find((*it).substr(1, (*it).size()-1)) != s2.end())
        {
            cout << (*it).substr(1, (*it).size()-1) << endl;
            return 0;
        }
    cout << "satisfiable";
 
    return 0;
}