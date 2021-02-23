#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
struct Act
{
    string s;
    int x;
} a[maxn];

int main()
{
    multiset<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i].s >> a[i].x;
    multiset<int>::iterator i;
    int cnt = 0;
    for (int j = 0; j < n; j ++)
    {
        switch (a[j].s[1])
        {
            case 'd': st.insert(a[j].x);
                cnt = 0;
                for (i = st.begin(); i != st.end(); i ++)
                    if (*i == a[j].x) cnt ++;
                cout << cnt << endl;
                break;
            case 'e': cnt = 0;
                for (i = st.begin(); i != st.end(); i ++)
                    if (*i == a[j].x) cnt ++;
                cout << cnt << endl;
                st.erase(a[j].x);
                break;
            case 's': bool judge = false;
                for (int k = 0; k < j; k ++)
                    if (a[k].s[1] == 'd' && a[k].x == a[j].x)
                    {
                        judge = true;
                        break;
                    }
                if (judge) cout << 1 << " ";
                else cout << 0 << " ";
                cnt = 0;
                for (i = st.begin(); i != st.end(); i ++)
                    if (*i == a[j].x) cnt ++;
                cout << cnt << endl;
                break;
        }
    }
    return 0;
}