# 目录

[1. 开关问题](#1-开关问题)

[2. 集合的整数表示](#2-集合的整数表示)

[3. 折半枚举](#3-折半枚举)

[4. 题目指南](#4-题目指南)



# 枚举

## 1. 开关问题

### 1.1 Face The Right Way

原题链接：[Face The Right Way](http://poj.org/problem?id=3276)

分析：根据题意，不难发现两点：

（1）交换区间反转的顺序对结果没有影响

（2）对同一个区间进行两次以上的反转是多余的

那么由此，问题就转换成了求需要被反转的区间的集合。

首先考虑最左端的牛，包含这头牛的区间只有一个，因此，如果这头牛面朝前方，我们就能知道这个区间不需要反转。

反之，如果这头牛面朝后方，对应的区间就必须进行反转，于是问题的规模就缩小了 1 。以此类推，就可以求出答案。

考虑时间复杂度：

我们需要对所有的 K 都进行一次求解，对于每个 K 都要考虑 N 头牛，最坏情况下需要 N - K + 1 次反转操作，而每次操作又要反转 K 头牛。

这样做的时间复杂度是：
$$
O(n^3)
$$
需要进行优化，考虑到反转 K 头牛不需要每次都进行模拟，可以设置如下数组：
$$
f[i] = 区间[i, i+K-1]进行了反转的话为1，否则为0
$$
这样，在考虑第 i 头牛时：
$$
如果 \sum_{j=i-K+1}^{i-1}{f[j]}为奇数，则这头牛的方向与起始方向是相反的，否则方向不变
$$
又有如下公式：
$$
\sum_{j=(i+1)-K+1}^{i}{f[j]} = \sum_{j=i-K+1}^{i-1}{f[j] + f[i] - f[i-K+1]}
$$
这样处理以后，复杂度降为：
$$
O(n^2)，其中n为牛的个数
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e3 + 10;
int n;
int dir[maxn]; // 牛的方向(0:F, 1:B)
int f[maxn]; // 区间[i, i+K-1]是否进行反转

// 固定K，求对应的最小操作回数
// 无解的话则返回-1
int calc(int K)
{
    memset(f, 0, sizeof(f));
    int cnt = 0;
    int sum = 0; // f的和
    for (int i = 0; i + K <= n; ++i)
    {
        // 计算区间[i, i+K-1]
        if ((dir[i] + sum) % 2) ++cnt, f[i] = 1;
        sum += f[i];
        if (i - K + 1 >= 0) sum -= f[i - K + 1];
    }
    // 检查剩下的牛是否有面朝后方的情况
    for (int i = n - K + 1; i < n; ++i)
    {
        if ((dir[i] + sum) % 2) return -1;
        if (i - K + 1 >= 0) sum -= f[i - K + 1];
    }
    return cnt;
}

int main()
{

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        char s[5];
        scanf("%s", s);
        dir[i] = s[0] == 'B' ? 1 : 0;
    }
    int K = 1;
    int M = n;
    for (int i = 1; i <= n; ++i)
    {
        int m = calc(i);
        if (m >= 0 && M > m) M = m, K = i;
    }
    printf("%d %d\n", K, M);

    return 0;
}
```

### 1.2 Fliptile

原题链接：[Fliptile](http://poj.org/problem?id=3279)

分析：根据上一题的经验，我们会想到，不妨先指定好最上面一行的翻转方案，那么此时能够翻转（1,1）的只剩下（2,1）了，就回到了类似上一题的情景。

最后，如果（M，1）~（M，N）并非全为白色，就意味着不存在可行的方案。

这样将第一行所有的翻转方式都尝试一次就能求出整个问题的最小步数。

时间复杂度为：
$$
O(MN2^N)，其中M，N表示矩阵的长和宽
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e3 + 10;
int dx[] = {-1, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0};
int m, n;
int tile[20][20];
int opt[20][20]; // 保存最优解
int flip[20][20]; // 保存中间结果

// 查询(x, y)的颜色
int get(int x, int y)
{
    int c = tile[x][y];
    for (int d = 0; d < 5; ++d)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= m) continue;
        if (ny < 0 || ny >= n) continue;
        c += flip[nx][ny];
    }
    return c % 2;
}

// 求出第1行确定情况下的最小操作次数
// 不存在解的话返回-1
int calc()
{
    for (int i = 1; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (get(i-1, j)) flip[i][j] = 1;
	
    // 判断最后一行是否全白
    for (int j = 0; j < n; ++j)
        if (get(m-1, j)) return -1;
	
    // 统计翻转的次数
    int cnt = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cnt += flip[i][j];
    return cnt;
}

int main()
{

    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &tile[i][j]);
    int cnt = -1;
    // 按照字典序尝试第一行的所有可能性
    for (int i = 0; i < 1 << n; ++i)
    {
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < n; ++j) flip[0][n - j - 1] = i >> j & 1;
        int num = calc();
        if (num >= 0 && (cnt < 0 || cnt > num))
        {
            cnt = num;
            memcpy(opt, flip, sizeof(opt));
        }
    }
    if (cnt < 0) printf("IMPOSSIBLE\n");
    else
    {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                printf("%d%c", opt[i][j], j + 1 == n ? '\n' : ' ');

    }

    return 0;
}
```

## 2. 集合的整数表示

当元素比较少时，可以用二进制码来表示，集合{0, 1, ..., n-1}的子集 S 可以用如下方式编码成整数：
$$
f(S) = \sum_{i \epsilon S}{2^i}
$$
这样表示以后，一些集合运算可以写成如下方式：

- 空集：0
- 只含有第 i 个元素的集合：1 << i
- 含有全部 n 个元素的集合：(1 << n) - 1
- 判断第 i 个元素是否属于集合 S ：if  ( S >> i & 1 )
- 向集合中加入第 i 个元素：S | 1 << i
- 从集合中去除第 i 个元素：S & ~( 1 << i )
- 集合 S 和 T 的并集： S | T
- 集合 S 和 T 的交集： S & T



例题：[猜字谜](https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/)

分析：根据题意，不难看出，我们不用考虑words[i]中重复的字符，以及字符的顺序。

换句话说就是 “abbbbcd” 与 "aaaaadcb"应该有相同的哈希值（a, b, c, d），于是我们可以想到计数器，计算每个哈希值的个数。

考虑到只有小写字母，也就是26个，于是可以用一个 int 整数（只要用到低26位二进制）来代表这个集合 S 。

对于每个puzzles[i]，长度固定为7，且word必须包含puzzle的第一个字母，于是我们可以在有限的空间内列举出所有puzzles[i]的组合。

我们使用一个 int 整数的低 7 位二进制位（也就是 0 ~ 6位）来表示 puzzles[i] 的所有组合，

固定其中第 6 位始终为 1（为了满足题目要求），然后枚举其余位的可能性。

最后对每个哈希值求和，例如：

对于其中某个组合 'abcd' 来说，它的hash值为（a, b, c, d）可以匹配所有words中hash值为（a, b, c, d）的word,，如"abbbbbcd", ”aaaaaaadcb“ 

同理组合 'abc' 可以匹配所有hash值为（a, b, c）的word。

将所有组合可匹配的值加起来，就是我们 puzzles[i] 对应的 answer[i] 。

时间复杂度为：
$$
O(m|w|+n2^{|p|})，其中m和n分别是数组words和puzzles的长度，|w|是word的最大长度50，|p|是puzzle的最大长度 7。
$$


```cpp
class Solution {
public:
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // 利用map来记录每个哈希值的个数
        unordered_map<int, int> mp;
        int n = words.size();
        for (auto & s : words)
        {
            int t = 0;
            for (auto & i : s) t |= 1 << (i - 'a');
            ++mp[t];
        }
        n = puzzles.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i)
            // 固定第6位为1，枚举其余位的组合
            for (int j = 0; j < 64; ++j)
            {
                int t = 0;
                t |= 1 << (puzzles[i][0] - 'a');
                for (int k = 0; k < 6; ++k)
                    if ((j >> k) & 1) t |= 1 << (puzzles[i][k+1] - 'a');
                ans[i] += mp[t];
            }
        
        return ans;
            
    }
};
```

## 3. 折半枚举

例题：[4个数的和为0](http://poj.org/problem?id=2785)

分析：从 4 个数列中选择的话，会超时，不过可以考虑将他们对半分成 AB 和 CD 再考虑。

具体做法是，将 C 和 D 中的数字组合枚举出来，再排序，然后运用二分搜索。

时间复杂度为：
$$
O(n^2logn)，其中n为数组长度
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 4e3 + 10;
int n;
int A[maxn], B[maxn], C[maxn], D[maxn];
int CD[maxn * maxn]; // C和D中数字的组合方法

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d%d", A+i, B+i, C+i, D+i);
    // 枚举从C和D中取出数字的所有方法
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            CD[i * n + j] = C[i] + D[j];
    sort(CD, CD + n * n);
    
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int cd = -(A[i] + B[j]);
            cnt += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
        }
    printf("%lld\n", cnt);
    
    return 0;
}
```



## 4. 题目指南

### 开关问题

- [Face The Right Way](#11-Face-The-Right-Way)

- [Fliptile](#12-Fliptile)

### 集合的整数表示

- [猜字谜](#2-集合的整数表示)

### 折半枚举

- [4个数的和为0](#3-折半枚举)
- [Programming Contest](docs/ProgrammingContest.md)

