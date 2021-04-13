# 目录

[1. 背包问题](#1-背包问题)

- [1.1 01背包](#11-01背包)
- [1.2 完全背包](#12-完全背包)
- [1.3 多重背包](#13-多重背包)

[2. 最长公共子序列](#2-最长公共子序列)

[3. 最长上升子序列](#3-最长上升子序列)

- [3.1 一维LIS](#31-一维LIS)
- [3.2 二维LIS](#32-二维LIS)
- [3.3 三维LIS](#33-三维LIS)

[4. 回文串问题](#4-回文串问题)

- [4.1 最长回文子串](#41-最长回文子串)
- [4.2 最长回文子序列](#42-最长回文子序列)

[5. 计数DP](#5-计数DP)

[6. 树形DP](#6-树形DP)

[7. 题目指南](#7-题目指南)



# 动态规划

## 1. 背包问题

### 1.1 01背包
有n种物品，每种物品只有 1 个，每种物品都有重量w[i]和价值v[i]，其中 0 <= i < n

问总容量为W的背包可以获得的最大价值。

状态 dp [j] 表示重量为 j 时获得的最大价值。

时间复杂度：
$$
O(nW)
$$


```cpp
int dp[max_w + 1];
for (int i = 0; i < n; ++i)
	for (int j = W; j >= w[i]; --j)
		dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
printf("%d\n", dp[W]);
```

如果给出的重量的数据范围很大，那么就不能使用上述的 dp 方式，可以考虑将重量 w 和价值 v 的地位对调：

状态：dp [i + 1] [j] 表示前 i 个物品中挑选出的价值总和为 j 时的总重量的最小值（不存在就是一个充分大的数值INF）

转移方程：dp [i + 1] [j] = min( dp [i] [j]，dp [i] [j - v[i] ] + w[i] )

入口：dp[0] [0] = 0，dp[0] [i] = INF 

出口：dp [n] [j] <= W 的最大的 j

时间复杂度：
$$
O(n\sum_{i}v_i)
$$

```cpp
int dp[max_n + 1][max_n * max_v + 1];
fill(dp[0], dp[0] + max_n * max_v + 1, INF);
dp[0][0] = 0;
for (int i = 0; i < n; ++i)
    for (int j = 0; j <= max_n * max_v; ++j)
        if (j < v[i]) dp[i+1][j] = dp[i][j];
		else dp[i+1][j] = min(dp[i][j], dp[i][j - v[i] + w[i]]);
int ans = 0;
for (int i = 0; i <= max_n * max_v; ++i)
    if (dp[n][i] <= W) ans = i;
printf("%d\n", ans);
```




### 1.2 完全背包

有n种物品，每种物品有无数个，每种物品都有重量w[i]和价值v[i]，其中 0 <= i < n

问总容量为W的背包可以获得的最大价值。

状态 dp [j] 表示重量为 j 时获得的最大价值。

时间复杂度：
$$
O(nW)
$$


```cpp
int dp[max_w + 1];
for (int i = 0; i < n; ++i)
	for (int j = w[i]; j <= W; ++j)
		dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
printf("%d\n", dp[W]);
```

可以发现，01背包和完全背包只是遍历方向不同。



### 1.3 多重背包

如果每种物品的数量既不是 1 个，也不是无数个，而是 m 个，可以用如下方式求解：
$$
把m_i分解为：m_i = 1 + 2 + 4 + \cdots + 2^k + a(0 \leqslant a < 2^{k+1})
$$
相当于将 m 利用 2 的幂进行分解，于是可以将物品看成：
$$
m_i个重量和价值为w_i和v_i的物品 \Rightarrow 重量和价值为w_i\times x，v_i\times x(x=1,2,\cdots,2^k,a)的k+2个物品
$$

这样，物品的总个数就变为：
$$
O(nlogm)
$$
使用一般的01背包就可以求解，时间复杂度为：
$$
O(nWlogm)
$$

```cpp
int dp[max_w + 1]; // DP数组

void solve()
{
    for (int i = 0; i < n; ++i)
    {
        int num = m[i];
        for (int k = 1; num > 0; k <<= 1)
        {
            int mul = min(k, num);
            for (int j = W; j >= w[i] * mul; --j)
                dp[j] = max(dp[j], dp[j - w[i] * mul] + v[i] * mul);
   			num -= mul;
        }
    }
    printf("%d\n", dp[W]);
}
```



## 2. 最长公共子序列

例题链接：[Common Subsequence](http://poj.org/problem?id=1458)

状态：dp [i] [j] 表示字符串 a 中前 i 个字符和 b 中前 j 个字符的最长公共子序列长度

转移方程：

- 如果 a[i] == b[j]，则 dp [i] [j] = dp [i-1] [j-1] + 1
- 否则 dp [i] [j] = max( dp [i] [j-1],dp [i-1] [j] )

入口：dp [0] [i] = dp [i] [0] = 0

出口：dp [n] [m]

时间复杂度：
$$
O(nm)，其中n，m表示字符串a，b的长度
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e3 + 10;
char a[maxn], b[maxn];
int dp[maxn][maxn];

int main()
{
    while (scanf("%s%s", a+1, b+1) != EOF)
    {
        int alen = strlen(a+1);
        int blen = strlen(b+1);
        // 状态初始化
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= alen; ++i)
            for (int j = 1; j <= blen; ++j)
            {
                // 状态转移
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        printf("%d\n", dp[alen][blen]);
    }

    return 0;
}
```



## 3. 最长上升子序列

最长上升子序列（LIS，Longest Increasing Subsequence）。

### 3.1 一维LIS

例题：[最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

方法一：动态规划做法

状态：dp[i]表示以nums[i]为结尾的最长上升子序列长度

转移方程：dp[i] = max( dp[j] ) + 1，其中，0 <= j < i 且 nums[j] < nums[i]

入口：dp[i] = 1

出口：max( dp[i] ) 

时间复杂度：
$$
O(n^2)，其中，n为数组长度
$$


```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
                // 状态转移
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```



方法二：贪心 + 二分

分析：构造一个dp数组，其中存放着nums数组的上升子序列，为了使其长度最长，应试图让其增长速度最慢。

以输入序列 [0，8，4，12，2]为例：

第一步插入 0，dp = [0]

第二步插入 8，dp = [0，8]

第三步插入 4，dp = [0，4]

第四步插入 12，dp = [0，4，12]

第五步插入 2，dp = [0，2，12]

使用二分查找来替换dp数组中的数，最后答案即为dp数组的长度。

时间复杂度：
$$
O(nlogn)，其中，n为数组长度
$$


```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] > dp[dp.size() - 1]) dp.emplace_back(nums[i]);
            else *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        return dp.size();
    }
};
```



### 3.2 二维LIS

例题：[俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)

方法一：动态规划做法：

考虑下面这个二维最长严格递增子序列的状态转移方程：
$$
dp[i] = \underset {0 \leqslant j < i} {max}(dp[j]) + 1，其中，w_j < w_i 且 h_j < h_i
$$
要使得这个状态转移方程能够被正确转移，我们需要保证：
$$
对于固定的i，任何满足w_j < w_i 且 h_j < h_i的j一定要在i之前已经转移完成
$$
因此，我们需要对原数组进行排序，按照 w 从小到大的顺序进行排序，而在这里，不需要第二关键字。

时间复杂度：
$$
O(n^2)，其中，n为信封个数
$$

```cpp
class Solution {
public:
    // 排序规则
    static bool cmp(vector<int> & a, vector<int> & b)
    {
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
                // 只有严格递增才进行转移
                if (envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);    
            
        }
        return ans;    
    }
};
```



方法二：类比一维LIS，考虑能否使用二分来优化DP：

根据题目，如果我们选择了 k 个信封，那么会有：
$$
w_0 < w_1 < \cdots < w_{k-1}
\\
h_0 < h_1 < \cdots < h_{k-1}
$$
考虑固定一个维度，再在另一个维度上进行选择。例如，固定 w，将数组按照 w 从小到大的顺序排序。

我们先假设 w 互不相同，那么排完序之后就有：
$$
w_0 < w_1 < \cdots < w_{k-1}
$$
此时我们完全可以忽略 w 维度，此时问题的答案就等价于找 h 维度上的最长严格递增子序列。此时时间复杂度为：
$$
O(nlogn)，其中，n为信封个数
$$
回到之前的问题，如果 w 的值可以相同，那么此时会产生一些错误，例如：

对于排完序的结果为 （1,1），（1,2），（1,3），（1,4），此时很显然，最长严格递增子序列为1。

但是当我们忽略 w 维度后，利用贪心 + 二分的方法求解时会得到答案 4，这是由于当 w 的值相同时，取了多个信封，而我们的本意是最多取一个。

因此，想到在排序时，将 h 作为第二关键字进行降序排序，这样，**在 w 值相同时，就最多选择一个信封**。

**需要注意的是，用这种方法求解最长严格递增子序列的值时维护的 dp 数组，其长度确实就是最终答案，但其内容却不是我们想要的。**

例如，对于样例：（1,1），（2,15），（3,20），（5,5），很显然最终答案是（1,1），（2,15），（3,20），长度为3,。

但是我们求解时的 dp 数组，内容却是 （1,5,20）。这一点很关键，这也意味着，该方法不再具有可扩展性，即不能推广到更高维。



```cpp
class Solution {
public:
    // 排序规则，注意与方法一的不同
    static bool cmp(vector<int> & a, vector<int> & b)
    {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
       	// 忽略w维度，求解h维度时的数组
        vector<int> dp;
        dp.emplace_back(envelopes[0][1]);
        for (int i = 1; i < n; ++i)
        {
            if (envelopes[i][1] < dp.back()) 
                *lower_bound(dp.begin(), dp.end(), envelopes[i][1]) = envelopes[i][1];
            else if (envelopes[i][1] > dp.back())
                dp.emplace_back(envelopes[i][1]);    
        }
        return dp.size();
    }
};
```



### 3.3 三维LIS

例题：[堆箱子](https://leetcode-cn.com/problems/pile-box-lcci/)

分析：低维的处理方法能否推广到高维，在二维中也略有讨论，具体结论是：

动态规划做法可扩展，只需按照任意一维排序，就可进行状态转移，当维度很大时，其不可忽略，设为 k，那么时间复杂度将是：
$$
O(n^2k)，其中，n为数组长度，k为维度
$$
但贪心 + 二分的做法却不可扩展。

当然还有更高效的做法，对于三维，可以利用 CDQ 分治来解决，其时间复杂度为：
$$
O(nlog^2n)，其中，n为数组长度
$$
四维情况可以使用 CDQ 分治套 CDQ 分治来解决，时间复杂度为：
$$
O(nlog^3n)，其中，n为数组长度
$$
但更高维的情况，无论是代码编写难度，还是时间复杂度，CDQ 分治方法都很难优于普通动态规划做法。

以下是普通动态规划做法：

```cpp
class Solution {
public:
    // 排序规则
    static bool cmp(vector<int> & a, vector<int> & b)
    {
        return a[0] > b[0];
    }
    int pileBox(vector<vector<int>>& box) {
        int n = box.size();
        sort(box.begin(), box.end(), cmp);
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i] = box[i][2];
            for (int j = 0; j < i; ++j)
                // 状态转移
                if (box[j][0] > box[i][0] && box[j][1] > box[i][1] && box[j][2] > box[i][2])
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
            ans = max(ans, dp[i]);
            
        }    
        return ans;

    }
};
```




## 4. 回文串问题
### 4.1 最长回文子串
原题链接：[最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

状态：假设 dp [i] [j] 表示 s[i ... j] 子串是否构成回文串，true 表示是回文串，false表示不是

转移方程：如果 dp [i] [j] == true，那么 dp [i-1] [j+1] = s[i-1] == s[j+1]

入口：从 dp [i] [j] = true 的地方开始 dp，而只有两种情况： 

（1）dp [i] [i] = true

（2）dp [i] [i+1] = true （此时 s[i] == s[i+1]）

出口：所有值为 true 的 dp [i] [j] 中，j - i + 1 的最大值

时间复杂度：
$$
O(n^2)，其中，n为字符串s的长度
$$


```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int start, len = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            int l, r;
            // 从dp[i][i]处开始扩展，遇到false就停止
            for (l = r = i; l >= 0 && r < n && s[l] == s[r]; --l, ++r);
            if (r - l - 1 > len) start = l + 1, len = r - l - 1;
            // 如果dp[i][i+1] == true，则从dp[i][i+1]开始扩展，遇到false就停止
            for (l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r);
            if (r - l - 1 > len) start = l + 1, len = r - l - 1;
        }
        return s.substr(start, len);
    }
};
```



### 4.2 最长回文子序列

原题链接：[最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)

状态：dp [i] [j] 表示字符串 s 的第 i 个字符到第 j 个字符构成的子序列中最长的回文序列长度

转移方程：

- 如果 s[i] == s[j]，那么 dp [i] [j] = dp [i+1] [j-1] + 2
- 否则 dp [i] [j] = max ( dp [i+1] [j]，dp [i] [j-1] )
- 注意遍历顺序，i 从最后一个字符开始遍历，j 从 i + 1开始遍历

入口：dp [i] [i] = 1

出口：dp [0] [n-1]

时间复杂度：
$$
O(n^2)，其中，n为字符串长度
$$

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        // 注意遍历顺序
        for (int i = n-1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j)
            {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};
```



## 5. 计数DP

例题：有 n 个无区别的物品，将它们划分成不超过 m 组，求出划分方法数模 M 的余数。

状态：dp [i] [j] 表示 j 的 i 划分总数

转移方程：也许可以得到下面的递推式：
$$
dp[i][j] = \sum_{k=0}^{j}dp[i-1][j-k]
$$
但是上述递推却是错误的，例如：1+1+2和1+2+1的划分被当作是不同的划分来计数了。

为了不重复计数，考虑 n 的 m 划分：
$$
a_i(\sum_{i=1}^{m}a_i = n)
$$
那么有：
$$
如果对每个i都有a_i > 0，那么\{a_i - 1\}就对应了n-m的m划分
\\
如果存在a_i = 0，那么就对应了n的m-1划分
$$
于是可以得出转移方程：dp [i] [j] = dp [i] [j - i] + dp [i - 1] [j]

入口：dp [0] [0] = 1

出口：dp [m] [n]

时间复杂度：
$$
O(nm)
$$

```cpp
int n, m;
int dp[max_m + 1][max_n + 1];
dp[0][0] = 1;
for (int i = 1; i <= m; ++i)
    for (int j = 0; j <= n; ++j)
        if (j - i >= 0) dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % M;
		else dp[i][j] = dp[i-1][j];
printf("%d\n", dp[m][n]);
```



## 6. 树形DP

树形DP，即在树上进行的DP，由于树固有的递归性质，树形DP一般都是递归进行的。

例题：[没有上司的舞会](https://www.luogu.com.cn/problem/P1352)

状态：dp [i] [j] 表示以 i 为根的子树的最优解，其中，第二维值为 0 表示不参加舞会，值为 1 表示参加舞会。

转移方程：（其中，下面的 x 表示 i 的儿子）

- 若上司不参加舞会，那么下属可以参加，也可以不参加，则有：
  $$
  dp[i][0] = \sum {}max(dp[x][1], dp[x][0])
  $$

- 若上司参加舞会，那么下属不参加：
  $$
  dp[i][1] = a[i] + \sum {} dp[x][0]
  $$

入口：dp [i] [1] = a[i]，其中，1 <= i <= n

出口：max( dp [i] [0]，dp [i] [1] ) ，其中，i 为根节点



```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 6e3 + 10;
int r[maxn];
vector<int> p[maxn];
int dp[maxn][2];
bool root[maxn];
int n;

void dfs(int cur, int pre)
{
    for (int i = 0; i < p[cur].size(); ++i)
    {
        int v = p[cur][i];
        if (v != pre)
        {
            dfs(v, cur);
            dp[cur][0] += max(dp[v][0], dp[v][1]);
            dp[cur][1] += dp[v][0];
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", r + i);
    for (int i = 1; i <= n; ++i) dp[i][1] = r[i];
    for (int i = 1; i < n; ++i)
    {
        int l, k;
        scanf("%d%d", &l, &k);
        root[l] = 1;
        p[k].push_back(l);
    }
    for (int i = 1; i <= n; ++i)
        if (!root[i])
        {
            dfs(i, -1);
            printf("%d\n", max(dp[i][0], dp[i][1]));
        }
    return 0;
}
```






## 7. 题目指南

### 最长公共子序列

- [Common Subsequence](#2-最长公共子序列)

### 最长上升子序列（LIS）

- [最长递增子序列（一维LIS）](#31-一维LIS)
- [俄罗斯套娃信封问题（二维 LIS）](#32-二维LIS)
- [堆箱子（三维 LIS）](#33-三维LIS)
- [最多可以参加的会议数目 II（LIS + 01背包）](docs/最多可以参加的会议数目.md)

### 回文串问题

- [最长回文子串](#41-最长回文子串)
- [最长回文子序列](#42-最长回文子序列)
- [由子序列构造的最长回文串](docs/由子序列构造的最长回文串.md)
- [分割回文串](docs/分割回文串.md)

### 其他线性DP

- [Zipper](docs/Zipper.md)
- [滑雪](docs/滑雪.md)
- [Jumping Cows](docs/JumpingCows.md)
- [Sequence Matching](docs/SequenceMatching.md)
- [摘樱桃](docs/摘樱桃.md)

### 计数DP

- [Robot on Grid](docs/RobotonGrid.md)

### 树形DP

- [没有上司的舞会](#6-树形DP)
- [打家劫舍](docs/打家劫舍.md)
- [二叉树染色](docs/二叉树染色.md)



### 有生之年

石子合并（区间dp）：https://ac.nowcoder.com/acm/problem/51170

合并回文子串（区间dp）：https://ac.nowcoder.com/acm/problem/13230

Magical Ornament（状压dp）：https://atcoder.jp/contests/abc190/tasks/abc190_e

