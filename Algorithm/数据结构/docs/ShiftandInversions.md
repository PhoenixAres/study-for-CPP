# Shift and Inversions

原题链接：[Shift and Inversions](https://atcoder.jp/contests/abc190/tasks/abc190_f)

分析：利用树状数组解决逆序对问题，我们的目的是：
$$
对于每个j，快速求出i < j 且 a_i > a_j 的i的个数
$$
考虑使用树状数组**维护每个数的出现次数**，我们按照数组顺序将每个数插入树状数组，即 update( a[i]，1 )。

在每个数插入之前，需要询问在之前插入的数中严格比它大的数的个数，考虑此时的 query 操作，query(x) 求的是 1~ x 的前缀和，也就是**小于等于 x 的数的个数**，那么我们每次在**插入之前**利用 query(n) - query(x) 来查询严格大于 x 的数，其中，n 是维护的数中的最大值。

对于本题，不光要求原数组的逆序数，还要依次求出循环数组的逆序数，循环数组即：
$$
b_0, b_1, \cdots, b_{n-1}, b_i = a_{i + k \ mod \ n}，其中，k = 1, 2, \cdots, n-1
$$
那么每次操作依然是询问 query(n) - query(x)来求取逆序数，但需要注意的是，因为数组在滚动，我们需要减去 query(x - 1)，这表示：

例如，a[1] 原本是最先插入数组的，我们在插入 a[2]，a[3] 时，如果 a[2]，a[3] 均小于 a[1]，我们会求得 2 个逆序对，但因为数组滚动，a[1] 从最左边移动到了最右边，那么上述求得的 2 个逆序对就不再存在了，需要减去。

时间复杂度：
$$
O(nlogn)，其中，n为数组长度
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 3e5 + 10;
int n, a[maxn], BIT[maxn];
 
int lowbit(int x)
{
    return x & -x;
}
 
void update(int s, int x)
{
    for (int i = s; i <= n; i += lowbit(i)) BIT[i] += x;
}
 
int query(int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += BIT[i];
    return ans;
}
 
int main()
{
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        // 树状数组使用时，避免将0插入树状数组
        ++a[i];
        // 相当于总的个数减去小于等于a[i]的个数，即求大于a[i]的个数
        ans += query(n) - query(a[i]);
        // 更新a[i]的出现次数
        update(a[i], 1);
    }
    printf("%lld\n", ans);
    for (int i = 1; i < n; ++i)
    {
        // 由于数组滚动，需要将之前和a[i]有关的逆序对删除
        ans -= query(a[i] - 1);
        // 依然是查询逆序对个数
        ans += query(n) - query(a[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
```

