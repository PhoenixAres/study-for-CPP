#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 4e5 + 10;
int n;
ll C, diff[maxn], a[maxn], b[maxn], c[maxn];
set<ll> st;
map<ll, int> mp;
map<int, ll> pm;
 
int main()
{
    scanf("%d%lld", &n, &C);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld%lld", a+i, b+i, c+i);
        ++b[i];
        st.insert(a[i]);
        st.insert(b[i]);
    }
    int tot = 0;
    for (auto p = st.begin(); p != st.end(); ++p) mp[*p] = ++tot, pm[tot] = *p;
    for (int i = 1; i <= n; ++i)
    {
        diff[mp[a[i]]] += c[i];
        diff[mp[b[i]]] -= c[i];
    }
    for (int i = 1; i <= tot; ++i) diff[i] += diff[i-1];
    ll ans = 0;
    for (int i = 1; i < tot; ++i) ans += min(C, diff[i])*(pm[i+1]-pm[i]);
    printf("%lld\n", ans);
    return 0;
}