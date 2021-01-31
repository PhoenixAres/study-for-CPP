#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

multiset<int> st;
char a[maxn];

int main()
{
    int t;
    cin >> t;
    memset(a, 0, sizeof(a));
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x;
            cin >> x;
            st.insert(x);
            a[x] = 1;
            cout << st.count(x) << endl;
        }
        if (s == "ask")
        {
            int x;
            cin >> x;
            if (a[x]) cout << "1 ";
            else cout << "0 ";
            cout << st.count(x) << endl;
        }
        if (s == "del")
        {
            int x;
            cin >> x;
            cout << st.count(x) << endl;
            st.erase(x);
        }
    }

	return 0;
}