# 目录

[1. 优先队列和堆](#1-优先队列和堆)

[2. 单调栈](#2-单调栈)

[3. 单调队列](#3-单调队列)

[4. 并查集](#4-并查集)

[5. ST表](#5-ST表)

[6. 树状数组](#6-树状数组)

[7. 线段树](#7-线段树)

[8. 分桶法和平方分割](#8-分桶法和平方分割)

[9. 题目指南](#9-题目指南)




# 数据结构

## 1. 优先队列和堆

能够完成下列操作的数据结构叫做优先队列（二叉堆）：

- 插入一个数值
- 取出最小（大）的数值（获得数值，并且删除）

二叉堆是一类特殊的树，其重要性质是儿子的值一定不小（大）于父亲的值。

这两种操作所花的时间都和树的深度成正比，因此时间复杂度为：
$$
O(logn)
$$


例题：[Expedition](http://poj.org/problem?id=2431)

分析：根据题意，在卡车开往终点的途中，只有在加油站才可以加油。

但是如果认为**在到达加油站 i 时，就获得了一次在之后的任何时候都可以加其提供的汽油的权利**，在解决问题上应该是一样的。

而在之后需要加油时，就认为是在之前经过的加油站加的油就可以了。

那么很显然，如果希望到达终点时加油次数最少，那么每次加油应选择最多的来加油。

思路如下：每次经过加油站 i 时，往优先队列里加入其提供的汽油数量。每当没油了：

- 如果优先队列也是空的，则无法到达终点
- 否则取出优先队列中的最大元素，用来加油

时间复杂度：
$$
O(nlogn)，其中，n为加油站数量
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 10;
int L, P, N;
pair<int, int> s[maxn];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d%d", &s[i].first, &s[i].second);
    scanf("%d%d", &L, &P);
    // 将加油站到终点的距离转换为加油站到起点的距离
    for (int i = 0; i < N; ++i) s[i].first = L - s[i].first;
    // 按照加油站到起点距离从小到大排序
    sort(s, s + N);
    // 为了写起来方便，把终点也认为是加油站
    s[N].first = L;
    s[N].second = 0;
    priority_queue<int> pq;
    // ans表示加油次数，pos表示现在所在位置，tank表示油箱中汽油数量
    int ans = 0, pos = 0, tank = P;
    for (int i = 0; i <= N; ++i)
    {
        // 接下来要前进的距离
        int d = s[i].first - pos;
        // 不断加油直到油量足够走到下一个加油站
        while (tank < d)
        {
            if (pq.empty()) { printf("-1\n"); return 0; }
            tank += pq.top();
            pq.pop();
            ++ans;
        }
        tank -= d;
        pos = s[i].first;
        pq.push(s[i].second);

    }
    printf("%d\n", ans);
    return 0;
}
```



## 2. 单调栈

栈是一种后进先出的数据结构，而单调栈满足如下性质（当然大于号可以替换为小于号），即满足单调性：
$$
设在栈里的元素从上到下的值为x_i，则x_i > x_{i+1}
$$
例题：[Largest Rectangle in a Histogram](http://poj.org/problem?id=2559)

分析：设面积最大的长方形左端是 L，右端是 R，那么高度一定如下：
$$
H = min\{h_i | L \leqslant i < R\}
$$
因此，我们可以根据给出的 H，来固定 i 进行分析，此时，L 和 R 可以表示为：
$$
L[i] = (j \leqslant i 且 h_{j-1} < h_i 的最大的j)
\\
R[i] = (j > i 且 h_j < h_i 的最小的j)
$$
此时最大的面积就是：
$$
max\{ h_i \times (R[i] - L[i]) | 0 \leqslant i < n\}
$$
L 和 R 可以利用单调栈进行高效求解，维护如下这样的栈：
$$
设在栈里的元素从上到下的值为x_i，则x_i > x_{i+1} 且 h_{x_i} > h_{x_{i+1}}
$$
算法按照如下步骤进行（以计算 L[i] 为例）：

- 如果栈顶元素的高度大于等于当前高度，则不断取出栈顶元素。
- 若栈为空，则 L[i] = 0，否则 L[i] = 栈顶元素 j + 1。
- 将 i 压入栈中。

时间复杂度：
$$
O(n)，n为长方形个数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int n;
int h[maxn], L[maxn], R[maxn];

int main()
{
    scanf("%d", &n);
    while (n)
    {
        for (int i = 0; i < n; ++i) scanf("%d", h+i);
        // 维护L的单调栈
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && h[i] <= h[st.top()]) st.pop();
            L[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        while (!st.empty()) st.pop();
		// 维护R的单调栈
        for (int i = n-1; i >= 0; --i)
        {
            while (!st.empty() && h[i] <= h[st.top()]) st.pop();
            R[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, 1LL * h[i] * (R[i] - L[i]));
        printf("%lld\n", ans);
        scanf("%d", &n);
    }

    return 0;
}
```



## 3. 单调队列

一个双端队列中的元素始终保持单调性，这个数据结构被称为单调队列。

例题：[绝对差不超过限制的最长连续子数组](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

分析：滑动窗口 + 单调队列，在滑动过程中，我们在关心窗口内的最大值和最小值，分别利用一个单调队列来记录。

时间复杂度：
$$
O(n)，其中，n为数组长度
$$


```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 记录窗口内最小值
        deque<int> minSeq;
        // 记录窗口内最大值
        deque<int> maxSeq;
        int l = 0;
        int n = nums.size();
        int ans = 0;
        for (int r = 0; r < n; ++r)
        {
            // 保持单调性
            while (!minSeq.empty() && nums[minSeq.back()] >= nums[r]) minSeq.pop_back();
            while (!maxSeq.empty() && nums[maxSeq.back()] <= nums[r]) maxSeq.pop_back();
            minSeq.push_back(r);
            maxSeq.push_back(r);
            // 窗口不符合要求时，左边滑动
            while (!minSeq.empty() && !maxSeq.empty() && nums[maxSeq.front()] - nums[minSeq.front()] > limit) 
            {
                
                if (l == maxSeq.front()) maxSeq.pop_front();
                if (l == minSeq.front()) minSeq.pop_front();
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```



## 4. 并查集

并查集是一种用来管理元素分组情况的数据结构，可以高效地进行如下操作（需要注意的是，无法进行分割操作）：

- 查询元素 a 和元素 b 是否属于同一组
- 合并元素 a 和元素 b 所在的组

并查集使用树形结构实现，在树形结构中，如果发生退化情况，那么复杂度会变高，因此，需要进行避免：

- 对于每棵树，记录这棵树的高度（h）
- 合并时，如果两棵树的 h 不同，那么从 h 小的向 h 大的连边。

时间复杂度：
$$
O(\alpha(n))，这里，\alpha(n)是阿克曼函数(A(n,n))的反函数，这比O(logn)要快
$$

例题：[并查集板子](https://www.luogu.com.cn/problem/P3367)


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 10;
int par[maxn];  // 父亲
int h[maxn]; // 树的高度

// 初始化n个元素
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        par[i] = i;
        h[i] = 0;
    }
}

// 查询树的根
int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

// 合并x和y所属的集合
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (h[x] < h[y]) par[x] = y;
    else
    {
        par[y] = x;
        if (h[x] == h[y]) ++h[x];
    }
}

// 判断x和y是否属于同一集合
bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1) unite(y, z);
        else
        {
            if (same(y, z)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
```



## 5. ST表

ST表（Sparse Table，稀疏表）是用于解决**可重复贡献问题**的数据结构。

什么是可重复贡献问题？对于运算 opt，如果满足 x opt x = x，则对应的区间询问就是一个可重复贡献的问题，例如 max(x, x) = x，gcd(x, x) = x。但是区间和就不具有这个性质，如果求区间和的时候采用的预处理区间重叠了，则会导致重叠部分被计算两次，这是我们所不愿意看到的。另外， opt 还必须满足结合律才能使用 ST 表求解。

例题：[ST表板子](https://www.luogu.com.cn/problem/P3865)

分析：ST表是利用的是倍增的思想，拿最大值来说，具体实现如下：

$$
令f[i][j]表示区间[i, i+2^j-1]的最大值
\\
那么显然有f[i][0] = a_i
\\
根据定义式，第二维就相当于倍增时跳了2^j-1步，那么可以写出f[i][j] = max(f[i][j-1], f[i+2^{j-1}][j-1])
$$
以上就是预处理部分，而对于查询，可以简单实现如下：
$$
对于每个查询[l, r]，我们把它分成两部分：f[l][l+2^s-1]与f[r-2^s+1][r]，其中，s = floor(log_2(r-l+1))
$$
根据上面对于可重复贡献问题的定义，由于最大值是可重复贡献问题，重叠并不会对区间最大值产生影响。又因为这两个区间完全覆盖了需要查询的区间，可以保证答案的正确性。

时间复杂度：
$$
预处理O(nlogn)，查询O(1)，其中，n为数组长度
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int f[maxn][22];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &f[i][0]);
    for (int j = 1; j <= 21; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int s = log2(r - l + 1);
        printf("%d\n", max(f[l][s], f[r-(1<<s)+1][s]));
    }

    return 0;
}
```



## 6. 树状数组

树状数组（Binary Indexed Tree，BIT）是能够完成如下操作的数据结构：

给定一个初始值全为0的数列 a：

- 给定 i，计算 i 的前缀和
- 给定 i 和 x，让第 i 个元素自增 x

时间复杂度：
$$
O(logn)，其中，n为数组长度
$$

### 6.1 单点更新区间查询

例题：[单点更新区间查询](https://www.luogu.com.cn/problem/P3374)

时间复杂度：
$$
O(nlogn + mlogn)，其中，n为数组长度，m为查询次数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e5 + 10;
int n, m, BIT[maxn];

int lowbit(int x)
{
    return x & -x;
}

// 让第s个数自增x
void update(int s, int x)
{
    for (int i = s; i <= n; i += lowbit(i)) BIT[i] += x;
}

// 查询第x个数的前缀和
int query(int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += BIT[i];
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        update(i, x);
    }
    while (m--)
    {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1) update(x, y);
        else printf("%d\n", query(y) - query(x-1));
    }
    return 0;
}
```

### 6.2 区间更新单点查询

例题：[区间更新单点查询](https://www.luogu.com.cn/problem/P3368)

分析：算是树状数组的一个小变式，关键是要理解树状数组在干什么。

将一个区间里的数全部加上一个数 k，可以想到用差分的方法，而差分是前缀和的逆运算，于是可以利用这个性质来单点求值。

因此，此时**我们利用树状数组维护的其实是原数组的差分数组**。

时间复杂度：
$$
O(nlogn + mlogn)，其中，n为数组长度，m为查询次数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 5e5 + 10;
int n, m;
int BIT[maxn], a[maxn];

int lowbit(int x)
{
    return x & (-x);
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
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    // 利用树状数组维护差分数组
    for (int i = 1; i <= n; ++i) update(i, a[i]-a[i-1]);
    while (m--)
    {
        int p, x, y, k;
        scanf("%d%d", &p, &x);
        if (p == 1) scanf("%d%d", &y, &k);
        if (p == 1) update(x, k), update(y+1, -k);
        // 求差分数组的前缀和就是求单个元素的值
        else printf("%d\n", query(x));
    }
    return 0;
}
```

### 6.3 区间更新区间查询

这其实是线段树的专利，线段树最基本的作用就是高效地对区间进行操作，如果要使用树状数组，需要考虑进行变更。

例题：[区间更新区间查询](http://poj.org/problem?id=3468)

分析：如果给区间 [l, r] 同时加上 x，会有如何变化？我们令：
$$
s(i) = 加上x之前的\sum_{j=1}^{i}a_j
\\
s'(i) = 加上x之后的\sum_{j=1}^{i}a_j
$$
那么有：
$$
i < l，s'(i) = s(i)
\\
l \leqslant i\leqslant r，s'(i) = s(i) + x\times (i-l+1) = s(i) + x\times i - x\times(l-1)
\\
r < i，s'(i) = s(i) + x\times (r-l+1)
$$
下面记 sum(bit，i ) 为树状数组 bit 的前 i 项和，我们构建两个树状数组 bit0 和 bit1，并且设：
$$
\sum_{j=1}^{i}a_j = sum(bit1, i) \times i + sum(bit0, i)
$$
那么在 [l, r] 区间上同时加上 x 可以看成是：

- 在 bit0 的 l 位置上加上 -x(l-1)
- 在 bit1 的 l 位置上加上 x
- 在 bit0 的 r+1 位置上加上 xr
- 在 bit1 的 r+1 位置上加上 -x

更一般地，如果操作得到的结果可以用 i 的 n 次多项式表示，那么就可以使用 n+1个树状数组来进行维护。

时间复杂度：
$$
O(nlogn + qlogn)，其中，n为数组长度，q为查询次数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int n, q;
ll bit0[maxn], bit1[maxn];

void update(ll * b, int s, ll x)
{
    for (int i = s; i <= n; i += i&-i) b[i] += x;
}

ll query(ll * b, int x)
{
    ll ans = 0;
    for (int i = x; i; i -= i&-i) ans += b[i];
    return ans;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        scanf("%lld", &x);
        update(bit0, i, x);
    }
    while (q--)
    {
        char s[5];
        int a, b;
        ll c;
        scanf("%s%d%d", s, &a, &b);
        if (s[0] == 'C')
        {
            scanf("%lld", &c);
            update(bit0, a, -c * (a-1));
            update(bit0, b+1, c * b);
            update(bit1, a, c);
            update(bit1, b+1, -c);
        }
        else
        {
            ll ans = query(bit1, b)*b + query(bit0, b);
            ans -= query(bit1, a-1)*(a-1) + query(bit0, a-1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
```



## 7. 线段树

线段树（Segment Tree）是一棵完美二叉树（Perfect Binary Tree），即所有的叶子的深度都相同，并且每个节点要么是叶子，要么是有两个儿子的树。

线段树是擅长处理区间的，树上的每个节点都维护一个区间。根维护的是整个区间，每个节点维护的是父亲的区间二等分后的其中一个子区间。

其对区间的操作的时间复杂度均为：
$$
O(logn)，n为元素个数
$$
而初始化的时间复杂度为：
$$
O(n)，n为元素个数
$$
例题：[线段树板子](https://www.luogu.com.cn/problem/P33720)

分析：线段树的核心是懒标记，**利用父节点的懒标记和子节点维护区间的左右端点，可以更新子节点的权值**。

本题中，更新操作是将一个区间内的数全部加上 k，我们用线段树维护区间信息：

- 每个节点维护一个区间 [ l，r ]
- 每个节点的权值表示该区间内所有数的和
- 每个节点的懒标记表示该区间里的每个数需要加上 lazy 
- 那么，当我们利用懒标记扩散更新时，每个节点的权值需要自增 lazy * ( r - l + 1)

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 2e5 + 10;

// 线段树结构
struct node
{
    int l, r;
    // 懒标记和权值
    ll lazy, w;
} tree[maxn << 2];
int n, m;

// 建树
void build(int l = 1, int r = n, int now = 1)
{
    // 懒标记初始化为0
    tree[now].l = l, tree[now].r = r, tree[now].lazy = 0;
    if (l == r) { scanf("%lld", &tree[now].w); return ; }
    int mid = (l + r) >> 1;
    int lson = now << 1;
    int rson = lson | 1;
    // 递归建树
    build(l, mid, lson);
    build(mid + 1, r, rson);
    tree[now].w = tree[lson].w + tree[rson].w;
}

// 将懒标记发挥作用
void push_down(int now)
{
    // 懒标记为0，则不发挥作用
    if (!tree[now].lazy) return ;
    int lson = now << 1;
    int rson = lson | 1;
    // 懒标记扩散到子节点
    tree[lson].lazy += tree[now].lazy;
    tree[rson].lazy += tree[now].lazy;
    tree[lson].w += tree[now].lazy * (tree[lson].r - tree[lson].l + 1);
    tree[rson].w += tree[now].lazy * (tree[rson].r - tree[rson].l + 1);
    tree[now].lazy = 0;
}

// 更新操作
void update(int l, int r, ll k, int now = 1)
{
    if (tree[now].l >= l && tree[now].r <= r)
    {
        // 更新懒标记和权值
        tree[now].w += k * (tree[now].r - tree[now].l + 1);
        tree[now].lazy += k;
        return ;
    }
    // 利用懒标记扩散更新
    push_down(now);
    int lson = now << 1;
    int rson = lson | 1;
    if (tree[lson].r >= l) update(l, r, k, lson);
    if (tree[rson].l <= r) update(l, r, k, rson);
    tree[now].w = tree[lson].w + tree[rson].w;
}

// 查询
ll query(int l, int r, int now = 1)
{
    if (tree[now].l >= l && tree[now].r <= r) return tree[now].w;
    // 利用懒标记扩散更新
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
```



## 8. 分桶法和平方分割

分桶法（bucket method）是把一排物品或者平面分成桶，每个桶分别维护自己内部的信息，以达到高效计算的目的的方法。

其中，平方分割（sqrt decomposition）是把排成一排的 n 个元素每 n^(1/2) 个分在一个桶内进行维护的方法的统称，这样可以使对区间的操作的复杂度降至：
$$
O(\sqrt n)
$$

例题：[K-th Number](http://poj.org/problem?id=2104)

分析：如果 x 是第 k 个数，那么一定有：

- 在区间中不超过 x 的数不少于 k 个
- 在区间中小于 x 的数有不到 k 个

因此，如果可以快速求出区间里不超过 x 的数的个数，就可以通过对 x 进行二分搜索来求出第 k 个数是多少。

接下来，考虑如何计算在某个区间内不超过 x 的数的个数。使用平方分割解决这个问题，把数列每 b 个一组分到各个桶里，每个桶内存有排序后的数列。

- 对于完全包含在区间内的桶，用二分搜索法进行计算
- 对于所在的桶不完全包含在区间内的元素，逐个检查

如果设：
$$
b = \sqrt n
$$
那么复杂度就变成：
$$
O((\frac{n}{b})logb + b) = O(\sqrt nlogn)
$$
其中，对每个元素和对每个桶的处理时间为：
$$
对每个元素：O(1)，对每个桶：O(logb)
$$
所以比起让桶的数量和桶内元素的个数尽可能接近，我们更应该把桶的数量设置成比桶内元素个数略少一些，这样可以使得程序更加高效。

因此如果设：
$$
b = \sqrt{nlogn}
$$
那么复杂度变成：
$$
O((\frac{n}{b})logb + b) = O(\sqrt{nlogn})
$$
接下来，只需要对 x 进行二分搜索就可以了，此时，整个算法的时间复杂度：
$$
O(nlogn + m\sqrt n log^{1.5}n)，其中，n为数组长度，m为查询次数
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int n, m, A[maxn];
int I[maxn], J[maxn], K[maxn];

int nums[maxn]; // 对A排序之后的结果
vector<int> bucket[maxn/1000]; // 每个桶排序之后的结果

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", A+i);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", I+i, J+i, K+i);
        --I[i];
        --J[i];
    }

    for (int i = 0; i < n; ++i)
    {
        bucket[i / 1000].push_back(A[i]);
        nums[i] = A[i];
    }

    sort(nums, nums + n);

    // 对每个桶进行排序，其中最后一个没有装满的桶不需要进行排序，因为对它的处理是暴力处理
    for (int i = 0; i < n / 1000; ++i) sort(bucket[i].begin(), bucket[i].end());

    for (int i = 0; i < m; ++i)
    {
        // 求[l, r)区间中的第k个数
        int l = I[i];
        int r = J[i] + 1;
        int k = K[i];

        int lb = 0;
        int ub = n-1;
        int ans = 0;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            int x = nums[mid];
            int tl = l;
            int tr = r;
            int cnt = 0;

            // 区间两端多出的部分
            while (tl < tr && tl % 1000) if (A[tl++] <= x) ++cnt;
            while (tl < tr && tr % 1000) if (A[--tr] <= x) ++cnt;
	
            // 对每个桶进行计算
            while (tl < tr)
            {
                int b = tl / 1000;
                cnt += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
                tl += 1000;
            }

            if (cnt >= k) ub = mid - 1, ans = mid;
            else lb = mid + 1;
        }
        printf("%d\n", nums[ans]);
    }

    return 0;
}
```




## 9. 题目指南

### 优先队列和堆

- [Expedition](#1-优先队列和堆)

### 单调栈

- [Largest Rectangle in a Histogram](#2-单调栈)

- [车队](docs/车队.md)

### 单调队列

- [绝对差不超过限制的最长连续子数组](#3-单调队列)

### 并查集

- [并查集板子](#4-并查集)
- [食物链](docs/食物链.md)
- [关押罪犯](docs/关押罪犯.md)
- [Reversible Cards](docs/ReversibleCards.md)
- [Silver Woods](docs/SilverWoods.md)

### ST表

- [ST表板子](#5-ST表)

- [Balanced Lineup G](docs/BalancedLineupG.md)

### 树状数组

- [单点更新区间查询](#61-单点更新区间查询)
- [区间更新单点查询](#62-区间更新单点查询)
- [区间更新区间查询](#63-区间更新区间查询)
- [Shift and Inversions](docs/ShiftandInversions.md)
- [换个角度思考](docs/换个角度思考.md)

### 线段树

- [线段树板子](#7-线段树)
- [区区区间](docs/区区区间.md)

### 分桶法和平方分割

- [K-th Number](#8-分桶法和平方分割)