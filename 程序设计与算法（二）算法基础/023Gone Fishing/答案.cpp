#include <bits/stdc++.h>
using namespace std;

struct lake
{
    int f, d;
};

struct fishing
{
    int n;
    int x;
    bool operator < (const fishing & a) const
    {
        if (n == a.n)
            return x < a.x;
        return n > a.n;
    }
};

struct S
{
    int sum;
    int t[30];
};

lake l[30];
int t[30];

int main()
{
    int n;
    scanf("%d", &n);
    while (n)
    {
        int h;
        scanf("%d", &h);
        h *= 60;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &l[i].f);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &l[i].d);
        for (int i = 1; i <= n - 1; ++i)
            scanf("%d", t + i);
        S maxfish;
        maxfish.sum = -1;
        multiset<fishing> st;
        multiset<fishing>::iterator p;
        for (int i = 1; i <= n; ++i)
        {
            int eh = h;
            for (int j = 1; j < i; ++j)
                eh -= t[j] * 5;
            if (eh < 5) break;
            int k = eh / 5;
            for (int m = 1; m <= i; ++m)
            {
                for (int j = 1; j <= k; ++j)
                {
                    fishing fs;
                    fs.x = m;
                    fs.n = l[m].f - l[m].d * (j - 1);
                    if (fs.n < 0) fs.n = 0;
                    st.insert(fs);
                }
            }
            S s;
            s.sum = 0;
            memset(s.t, 0, sizeof(s.t));
            for (int j = 1; j <= k; ++j)
            {
                p = st.begin();
                s.sum += p->n;
                ++s.t[p->x];
                st.erase(p);
            }
            if (maxfish.sum < s.sum)
                maxfish = s;
        }
        for (int i = 1; i <= n; ++i)
        {
            printf("%d", maxfish.t[i] * 5);
            if (i < n) printf(", ");
        }
        printf("\nNumber of fish expected: %d\n", maxfish.sum);
        scanf("%d", &n);
        if (n) printf("\n");
    }

    return 0;
}