#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;
int n;
string s;

int main()
{
    cin >> n >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'f') st.push(s[i]);
        else if (s[i] == 'o') st.push(s[i]);
        else if (s[i] == 'x')
        {
            if (!st.empty() && st.top() == 'o') {
                st.pop();
                if (!st.empty() && st.top() == 'f') {
                    n -= 3;
                    st.pop();
                    continue;
                }

            }
            while (!st.empty()) st.pop();
        }
        else
        {
            while (!st.empty()) st.pop();
        }
    }
    printf("%d\n", n);
    return 0;
}