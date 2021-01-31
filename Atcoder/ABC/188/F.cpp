#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
ll x, y;
map<ll, ll> mp;
 
ll dfs(ll y)
{
    if (y <= x) return x - y;
    if (mp.count(y)) return mp[y];
    ll step = y - x;
    if (y % 2) step = min(step, min(dfs(y+1), dfs(y-1)) + 1);
    else step = min(step, dfs(y/2) + 1);
    return mp[y] = step;
}
 
int main()
{
    cin >> x >> y;
    cout << dfs(y);
    return 0;
}