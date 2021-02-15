#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;

struct node
{
    int l, r;
    ll w, lazy;
} tree[maxn << 2];

int n, m;

void build(int l = 1, int r = n, int now = 1)
{
    tree[now].l = l, tree[now].r = r, tree[now].lazy = 0;
    if (l == r) { scanf("%lld", &tree[now].w); return ; }
    int mid = (l + r) >> 1;
    int lson = now << 1;
    int rson = lson | 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    tree[now].w = tree[lson].w + tree[rson].w;
}

void push_down(int now)
{
    if (!tree[now].lazy) return ;
    int lson = now << 1;
    int rson = lson | 1;
    tree[lson].lazy = tree[now].lazy;
    tree[rson].lazy = tree[now].lazy + tree[lson].r - tree[lson].l + 1;
    tree[lson].w = (2 * tree[lson].lazy + tree[lson].r - tree[lson].l) * (tree[lson].r - tree[lson].l + 1) >> 1;
    tree[rson].w = (2 * tree[rson].lazy + tree[rson].r - tree[rson].l) * (tree[rson].r - tree[rson].l + 1) >> 1;
    tree[now].lazy = 0;
}

void update(int l, int r, ll k, int now = 1)
{
    if (tree[now].l >= l && tree[now].r <= r)
    {
        tree[now].lazy = k + tree[now].l - l;
        tree[now].w = (2 * tree[now].lazy + tree[now].r - tree[now].l) * (tree[now].r - tree[now].l + 1) >> 1;
        return ;
    }
    push_down(now);
    int lson = now << 1;
    int rson = lson | 1;
    if (tree[lson].r >= l) update(l, r, k, lson);
    if (tree[rson].l <= r) update(l, r, k, rson);
    tree[now].w = tree[lson].w + tree[rson].w;
}

ll query(int l, int r, int now = 1)
{
    if (tree[now].l >= l && tree[now].r <= r) return tree[now].w;
    push_down(now);
    int lson = now << 1;
    int rson = lson | 1;
    ll ans = 0;
    if (tree[lson].r >= l) ans += query(l, r, lson);
    if (tree[rson].l <= r) ans += query(l, r, rson);
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    build();
    while (m--)
    {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1)
        {
            ll k;
            scanf("%lld", &k);
            update(x, y, k);
        }
        else printf("%lld\n", query(x, y));
    }

    return 0;
}
