#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 4e5 + 10;
int n;
struct node
{
    int id, v;
    node(int a = 0, int b = 0):id(a), v(b){}
} p[maxn];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 1<<n; ++i) scanf("%d", &p[i].v), p[i].id = i;
    for (int j = n; j >= 2; --j)
    {
        int tot = 0;
        for (int i = 1; i <= 1<<(j-1); ++i)
        {
            if (p[2*i-1].v < p[2*i].v) p[++tot] = p[2*i];
            else p[++tot] = p[2*i-1];
        }
    }
    if (p[1].v < p[2].v) printf("%d\n", p[1].id);
    else printf("%d\n", p[2].id);
 
    return 0;
}