#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e3 + 10;
int m, k;
struct f
{
    int x;
    f(int i):x(i){}
    bool operator < (const f & a) const
    {
        if (x < a.x && a.x-x-k > 0) return true;
        return false;
    }
};
set<f> st;

int main()
{
    scanf("%d%d", &m, &k);
    while (m--)
    {
        char s[10];
        int t;
        scanf("%s%d", s, &t);
        if (s[0] == 'a') st.insert(f(t));
        else if (s[0] == 'd') st.erase(f(t));
        else if (s[0] == 'q')
        {
            if (st.find(f(t)) != st.end()) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}