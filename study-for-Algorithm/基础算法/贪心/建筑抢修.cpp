#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e5 + 10;
int n;
pair<int, int> a[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].second, &a[i].first);
    sort(a+1, a+n+1);
    int now = 0;
    int ans = 0;
    priority_queue<int> pq;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].second + now <= a[i].first)
        {
            ++ans;
            now += a[i].second;
            pq.push(a[i].second);
        }
        else
        {
            if (!pq.empty() && pq.top() > a[i].second)
            {
                now -= pq.top();
                now += a[i].second;
                pq.pop();
                pq.push(a[i].second);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}