# 目录

[1. 快速幂](#1-快速幂)

[2. 整数分解定理与约数和](#2-整数分解定理与约数和)

[3. 素数筛法](#3-素数筛法)

- [埃式筛法](#31-埃式筛法)
- [欧式筛法](#32-欧式筛法)
- [区间筛](#33-区间筛)

[4. 最大公因数](#4-最大公因数)

[5 题目指南](#5-题目指南)

`

# 数学

## 1. 快速幂

快速幂板子：

```cpp
typedef long long ll;
ll ksm(ll a, ll k, ll mod)
{
    ll r = 1;
    a = a%mod;
    for (; k; k >>= 1, a = a*a%mod)
        if (k & 1) r = r*a%mod;
    return r;
}
```



## 2. 整数分解定理与约数和

```cpp
// 将整数n分解成质数的乘积
unordered_map<int, int> mp;
int k = sqrt(n);
for (int i = 2; i <= k; ++i)
    while (n%i == 0) ++mp[i], n /= i;
if (n > 1) ++mp[n];

// 计算整数n的约数和sum
int sum = 1;
for (auto & i : mp) 
    sum *= (1 - pow(i.first, i.second+1)) / (1 - i.first);
printf("%d\n", sum);
```



## 3. 素数筛法

### 3.1 埃式筛法

算法思想：我们希望枚举n以内素数，首先，将2到n范围内的所有整数写下来。其中最小的数字2是素数。将表中所有2的倍数都划去。表中剩余的最小数字是3，它不能被更小的数整除，所以是素数。再将表中所有3的倍数都划去。依此类推，如果表中剩余的最小数字是m时，m就是素数。然后将表中所有m的倍数都划去。像这样反复操作，就能依次枚举n以内的素数。

时间复杂度：
$$
O(nloglogn)
$$


```cpp
const int maxn = 1e8 + 10;
bool isprime[maxn]; 
void prime()
{
    for(int i = 2; i < maxn; ++i)
        if(!isprime[i])
            for(int j = 2*i; j < maxn; j += i)
                isprime[j] = 1;
}
```



改进的埃式筛法：

```cpp
const int maxn = 1e8 + 10;
bool isprime[maxn]; 
void prime()						
{
    for(int i = 2; i*i < maxn; ++i)
        if(!isprime[i])
            for(int j = i*i; j < maxn; j += i)
                isprime[j] = 1;
}
```

改进后的埃式筛法时间复杂度：（略优于欧式筛法）
$$
O(n)
$$


### 3.2 欧式筛法

时间复杂度：
$$
O(n)
$$

```cpp
const int maxn = 1e8 + 10;
bool check[maxn];
vector<int> p;
void prime()
{
    for (int i = 2; i < maxn; ++i)
    {
        if(!check[i]) p.push_back(i);
        for (int j = 0; j < p.size(); ++j)
        {
            if (i * p[j] >= maxn) break;
            check[i*p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}
```

欧式筛法必须在过程中记录每一个素数，而埃式筛法则不是必须。



放一张两种素数筛法的效率对比图：( 1e8范围 )

```cpp
                       素数个数         花费时间
埃式筛法：              5761456         2406 ms
改进的埃式筛法：         5761456         1453 ms
欧式筛法：              5761456         1622 ms
```



### 3.3 区间筛


```cpp
typedef long long ll;
const int maxn = 1e8 + 10;
bool is_prime[maxn];
bool is_prime_small[maxn];
void segment_sieve(ll a,ll b)
{
    for(ll i = 0; i*i <= b; ++i) is_prime_small[i] = false; 
    for(ll i = 0; i <= b-a; ++i) is_prime[i] = false; 
    for(ll i = 2; i*i <= b; ++i)
        if(!is_prime_small[i])
        {
            for(ll j = 2*i; j*j <= b; j += i) is_prime_small[j] = true; 	 
            //筛选[2,sqrt(b));
            //(a+i-1)/i得到最接近a的i的倍数，最低是i的2倍，然后筛选
            for(ll j = max(2LL, (a+i-1)/i)*i; j <= b; j += i) is_prime[j-a] = true;
        }
}
```



例题：[Prime Distance](https://ac.nowcoder.com/acm/contest/978/A)

给定两个整数L,R，求闭区间[L,R]中相邻两个质数差值最小的数对与差值最大的数对。当存在多个时，输出靠前的素数对。（多组数据）

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool is_prime[100000010];
bool is_prime_small[100000010];

void segment_sieve(ll a,ll b)
{
    for(ll i = 0; i*i <= b; ++i) is_prime_small[i]=false; 
    for(ll i = 0; i <= b-a; ++i) is_prime[i]=false; 
    for(ll i = 2; i*i <= b; ++i)
        if(!is_prime_small[i])
        {
            for(ll j = 2*i; j*j <= b; j += i) is_prime_small[j] = true; 
            for(ll j = max(2LL, (a+i-1)/i)*i; j <= b; j += i) is_prime[j-a] = true;
        }
}

int main()
{
    ll l, r;
    while (~scanf("%lld%lld", &l, &r))
    {
        if (l == 1) ++l;
        segment_sieve(l, r);
        ll m1, m2;
        m1 = 1 << 30;
        m2 = -1;
        bool flag = true;
        ll j = 0;
        ll ans[5] = {0};
        for (ll i = l; i <= r; ++i)
            if (!is_prime[i-l])
            {
                if (flag) j = i, flag = false;
                else
                {
                    ans[0] = 1;
                    if (i - j < m1) m1 = i-j, ans[1] = j, ans[2] = i;
                    if (i - j > m2) m2 = i-j, ans[3] = j, ans[4] = i;
                    j = i;
                }
            }
        if (ans[0]) printf("%lld,%lld are closest, %lld,%lld are most distant.\n", ans[1], ans[2], ans[3], ans[4]);
        else printf("There are no adjacent primes.\n");
    }


    return 0;
}

```



## 4. 最大公因数

使用辗转相除法求最大公因数：

```cpp
typedef long long ll;
ll gcd(ll x, ll y)
{
    ll t = x % y;
    while (t)
    {
        x = y;
        y = t;
        t = x % y;
    }
    return y;
}
```



与最大公因数相关的动态规划：

例题：[序列中不同最大公约数的数目](https://leetcode-cn.com/problems/number-of-different-subsequences-gcds/)

状态：dp[i] 表示当前遍历过的所有数中，所有 i 的倍数的最大公因数

转移方程：对于数组中的每一个数 x，我们枚举其因数 y，并使用 x 更新 dp[y]，即：

- 如果 dp[y] 为初始值（例如设为0），那么 dp[y] = x
- 否则，有 dp[y] = gcd( dp[y]，x )

 出口：若 dp[i] = i，那么 i 可以作为最终结果。

时间复杂度：
$$
O(n\sqrt{C} + ClogC)，其中，n为数组长度，C为数组中最大值
$$


```cpp
class Solution {
public:
    int gcd(int x, int y)
    {
        int t = x % y;
        while (t)
        {
            x = y;
            y = t;
            t = x % y;
        }
        return y;
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int dp[200010];
        memset(dp, 0, sizeof(dp));
        for (auto & i : nums)
            for (int j = 1; j*j <= i; ++j)
                if (i % j == 0)
                {
                    if (!dp[j]) dp[j] = i;
                    else dp[j] = gcd(dp[j], i);
                    if (j*j != i)
                    {
                        int x = i / j;
                        if (!dp[x]) dp[x] = i;
                        else dp[x] = gcd(dp[x], i);
                    }
                }
        int ans = 0;
        for (int i = 1; i <= 2e5; ++i) 
            if (dp[i] == i) ++ans;
        return ans;
    }
};
```





## 5. 题目指南

### 素数筛法

- [Prime Distance](#33-区间筛)

### 最大公因数

- [序列中不同最大公约数的数目](#4-最大公因数)

- [GCDorMIN](docs/GCDorMIN.md)


