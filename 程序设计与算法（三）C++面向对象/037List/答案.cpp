#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

list<int> ls[maxn];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s[0] == 'a')
        {
            int i, x;
            cin >> i >> x;
            ls[i].push_back(x);
        }
        if (s[0] == 'm')
        {
            int i, j;
            cin >> i >> j;
            ls[i].merge(ls[j]);
        }
        if (s[0] == 'u')
        {
            int i;
            cin >> i;
            ls[i].sort();
            ls[i].unique();
        }
        if (s[0] == 'o')
        {
            int i;
            cin >> i;
            ls[i].sort();
            list<int>::iterator p;
            for (p = ls[i].begin(); p != ls[i].end(); ++p)
                cout << *p << " ";
            cout << endl;
        }
        if (s[0] == 'n')
        {
            int i;
            cin >> i;
        }
    }


	return 0;
}