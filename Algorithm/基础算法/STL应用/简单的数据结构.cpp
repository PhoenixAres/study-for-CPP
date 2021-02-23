#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e3 + 10;
deque<int> d;
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int id, x;
        scanf("%d", &id);
        if (id == 1 || id == 3) scanf("%d", &x);
        if (id == 1) d.push_front(x);
        else if (id == 2) d.pop_front();
        else if (id == 3) d.push_back(x);
        else if (id == 4) d.pop_back();
        else if (id == 5) reverse(d.begin(), d.end());
        else if (id == 6)
        {
            printf("%d\n", d.size());
            for (int i = 0; i < d.size(); ++i)
                printf("%d ", d[i]);
            printf("\n");
        }
        else if (id == 7) sort(d.begin(), d.end());

    }

    return 0;
}