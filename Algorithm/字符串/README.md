# 目录

[1. 字符串哈希](#1-字符串哈希)

[2. 字典树](#2-字典树)

[3. KMP算法](#3-KMP算法)

[4 题目指南](#4-题目指南)



# 字符串

## 1. 字符串哈希

字符串哈希实质上就是**将不同的字符串转换成不同的整数**。这样做是为了**方便判断一个字符串是否出现过**。

字符串哈希的关键是**要将不同的字符串转换成不同的整数，即每个字符串都可以转换成唯一的整数**。

基本哈希方法：
$$
给定一个字符串S = s_1s_2...s_n，令idx(x) = x - 'a' + 1，x \in S（当然可以直接使用字符x的ASCII码）
$$
基本思路是将字符串S转换成一个base进制数，设 h[] 表示哈希值，p[] 表示当前位的基数，那么有：

```cpp
typedef long long ll;
// 获取s[l,...,r]的哈希值
ll get(int l, int r)
{
    return (h[r] - h[l-1] * p[r-l+1] % mod + mod) % mod;
}

// 计算字符串的哈希值
p[0] = 1;
for (int i = 1; i <= n; ++i)
{
    p[i] = p[i-1] * base % mod;
    h[i] = (h[i-1] * base + s[i]) % mod;
}
```

base 和 mod 的选择至关重要（因为我们希望尽可能地降低冲突率），其中，base 和 mod 都为素数。

base 通常选择131,13331,2333等，而 mod 的选择有以下几种。

**自然溢出法**

这种方法是利用 unsigned long long 的范围自然溢出：
$$
mod = 2^{64}-1
$$
**单哈希法**

我们选择 mod > base 的素数，素数选择参考如下：

| 下界  | 上界  | 冲突率     | 素数      |
| ---- | ---- | --------- | ---------- |
| 2^5  | 2^6  | 10.416667 | 53         |
| 2^6  | 2^7  | 1.041667  | 97         |
| 2^7  | 2^8  | 0.520833  | 193        |
| 2^8  | 2^9  | 1.302083  | 389        |
| 2^9  | 2^10 | 0.130208  | 769        |
| 2^10 | 2^11 | 0.455729  | 1543       |
| 2^11 | 2^12 | 0.227865  | 3079       |
| 2^12 | 2^13 | 0.113932  | 6151       |
| 2^13 | 2^14 | 0.008138  | 12289      |
| 2^14 | 2^15 | 0.069173  | 24593      |
| 2^15 | 2^16 | 0.010173  | 49157      |
| 2^16 | 2^17 | 0.013224  | 98317      |
| 2^17 | 2^18 | 0.002543  | 196613     |
| 2^18 | 2^19 | 0.006358  | 393241     |
| 2^19 | 2^20 | 0.000127  | 786433     |
| 2^20 | 2^21 | 0.000318  | 1572869    |
| 2^21 | 2^22 | 0.000350  | 3145739    |
| 2^22 | 2^23 | 0.000207  | 6291469    |
| 2^23 | 2^24 | 0.000040  | 12582917   |
| 2^24 | 2^25 | 0.000075  | 25165843   |
| 2^25 | 2^26 | 0.000010  | 50331653   |
| 2^26 | 2^27 | 0.000023  | 100663319  |
| 2^27 | 2^28 | 0.000009  | 201326611  |
| 2^28 | 2^29 | 0.000001  | 402653189  |
| 2^29 | 2^30 | 0.000011  | 805306457  |
| 2^30 | 2^31 | 0.000000  | 1610612741 |



**双哈希法**

双哈希就是对一个哈希值用两个不同的素数 mod 进行两次取模操作，然后用一对数 <hash1[n]，hash2[n]> 来表示一个字符串的哈希值，双哈希法的冲突率几乎为0。

```cpp
typedef long long ll;
ll geth1(int l, int r)
{
    return (h1[r] - h1[l-1] * p1[r-l+1] % mod1 + mod1) % mod1;
}

ll geth2(int l, int r)
{
    return (h2[r] - h2[l-1] * p2[r-l+1] % mod2 + mod2) % mod2;
}

// 计算双哈希值
p1[0] = p2[0] = 1;
for (int i = 1; i <= n; ++i)
{
    p1[i] = p1[i-1] * base % mod1;
    p2[i] = p2[i-1] * base % mod2;
    h1[i] = (h1[i-1] * base + s[i]) % mod1;
    h2[i] = (h2[i-1] * base + s[i]) % mod2;
}
```



## 2. 字典树

Trie，又称前缀树或字典树，是一棵有根树，其每个节点包含以下字段：

- int children[26]，数组长度为 26，即小写英文字母的数量。此时 children[0] 对应小写字母 a，children[1] 对应小写字母 b，…，children[25] 对应小写字母 z。
- bool ext，表示该节点是否为字符串的结尾。

例题：[实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

每次插入和查询的时间复杂度：
$$
O(|S|)，其中，|S|表示字符串长度
$$

```cpp
class Trie {
    int trie[100000][30];
    bool ext[100000];
    int cnt;
public:
    /** Initialize your data structure here. */
    Trie() {
        memset(trie, 0, sizeof(trie));
        memset(ext, 0, sizeof(ext));
        cnt = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0;
        for (auto & i : word)
        {
            int c = i - 'a';
            if (!trie[p][c]) trie[p][c] = ++cnt;
            p = trie[p][c];
        }
        ext[p] = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p = 0;
        for (auto & i : word)
        {
            int c = i - 'a';
            if (!trie[p][c]) return 0;
            p = trie[p][c];
        }
        return ext[p];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int p = 0;
        for (auto & i : prefix)
        {
            int c = i - 'a';
            if (!trie[p][c]) return 0;
            p = trie[p][c];
        }
        return 1;
    }
};

```



## 3. KMP算法

例题：[KMP字符串匹配](https://www.luogu.com.cn/problem/P3375)

next数组含义：next [ i ] 表示以 p [ i ] 为结尾的能够匹配的最长前缀

构造模式串p的next数组：

```cpp
// m为模式串p的长度
for (int i = 2, j = 0; i <= m; ++i)
{
    while (j && p[i] != p[j+1]) j = ne[j];
    if (p[i] == p[j+1]) ++j;
    ne[i] = j;
}
```

查询模式串p在字符串s中的出现位置：

```cpp
// m为模式串p的长度
// n为字符串s的长度
for (int i = 1, j = 0; i <= n; ++i)
{
    while (j && s[i] != p[j+1]) j = ne[j];
    if (s[i] == p[j+1]) ++j;
    if (j == m)
    {
        printf("%d\n", i - m + 1);
        j = ne[j];
    }
}
```



时间复杂度：
$$
O(n + m)，其中，n为字符串s的长度，m为模式串p的长度
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e6 + 10;
char s[maxn], p[maxn];
int n, m;
int ne[maxn];

int main()
{
    scanf("%s%s", s+1, p+1);
    n = strlen(s+1);
    m = strlen(p+1);

    for (int i = 2, j = 0; i <= m; ++i)
    {
        while (j && p[i] != p[j+1]) j = ne[j];
        if (p[i] == p[j+1]) ++j;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= n; ++i)
    {
        while (j && s[i] != p[j+1]) j = ne[j];
        if (s[i] == p[j+1]) ++j;
        if (j == m)
        {
            printf("%d\n", i - m + 1);
            j = ne[j];
        }
    }

    for (int i = 1; i <= m; ++i)
        printf("%d%c", ne[i], i == m ? '\n' : ' ');


    return 0;
}
```





## 4. 题目指南

### 字符串哈希

- [字符串哈希模板](docs/字符串哈希模板.md)
- [矩阵](docs/矩阵.md)

### 字典树

- [实现 Trie (前缀树)](#2-字典树)
- [于是他错误的点名开始了](docs/于是他错误的点名开始了.md)
- [统计异或值在范围内的数对有多少](docs/统计异或值在范围内的数对有多少.md)
- [与数组中元素的最大异或值](docs/与数组中元素的最大异或值.md)

### KMP算法

- [KMP字符串匹配](#3-KMP算法)