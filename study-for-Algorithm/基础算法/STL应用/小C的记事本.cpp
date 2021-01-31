#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e3 + 10;
string s;
int n;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        s.clear();
        stack<string> st;
        st.push(s);
        int id;
        for (int i = 1; i <= n; ++i)
        {
            cin >> id;
            string t;
            int k;
            if (id == 1) cin >> t;
            if (id == 2 || id == 3) cin >> k;
            if (id == 1) s += t, st.push(s);
            else if (id == 2) s.erase(s.size()-k), st.push(s);
            else if (id == 3) cout << s[k-1] << endl;
            else if (id == 4) st.pop(), s = st.top();
        }
    }
    return 0;
}
