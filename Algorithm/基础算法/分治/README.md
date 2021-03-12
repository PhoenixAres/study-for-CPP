# 目录

[1. 数列上的分治法](#1-数列上的分治法)

- [1.1 归并排序](#11-归并排序)

- [1.2 逆序数](#12-逆序数)

- [1.3 至少有K个重复字符的最长子串](#13-至少有K个重复字符的最长子串)

[2. 题目指南](#2-题目指南)



# 分治

分治法通过将问题划分为规模更小的子问题，递归地解决划分后的子问题，再将结果合并从而高效地解决问题。

## 1. 数列上的分治法

### 1.1 归并排序

基本思想：

（1）开始进行归并排序

（2）对一个数组，如果其长度等于 1，那么此时这 1 个长度的数组已经有序了，转向（5）。

（3）如果数组长度大于 1，将其分为前一半和后一半，分别对前一半和后一半进行归并排序，即对前一半和后一半分别转向（1）

（4）此时，该数组的前一半和后一半都已经变成了有序数组，将他们合并成一个有序数组。

（5）排序完成。

时间复杂度：
$$
O(nlogn)，其中n为数组长度
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int a[maxn];
int b[maxn];
int n;

// 将有序数组a[start], a[start+1], ..., a[mid] 和有序数组 a[mid+1], a[mid+2], ..., a[end]合并
void Merge(int start, int mid, int end)
{
    int k = 0;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= end) b[k++] = a[j++];
    for (int i = 0; i < k; i ++) a[start+i] = b[i];
}

// 归并排序
void MergeSort(int start, int end)
{
    if (start == end) return ;
    int mid = start + (end - start) / 2;
    MergeSort(start, mid);
    MergeSort(mid+1, end);
    Merge(start, mid, end);

}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    MergeSort(1, n);
    for (int i = 1; i <= n; ++i)
    {
        if (i < n) printf("%d ", a[i]);
        else printf("%d\n", a[i]);
    }

    return 0;
}
```



### 1.2 逆序数

原题链接：[逆序数](https://ac.nowcoder.com/acm/problem/15163)

分析：可以在归并排序的过程中，统计逆序数的个数，我们考虑数列A，将A的前一半称为B，后一半称为C

那么数列A中的所有逆序对必属于下面三者之一：

（1）i，j 都属于数列 B 的逆序对 （i，j）

（2）i，j 都属于数列 C 的逆序对 （i，j）

（3）i 属于数列B，而 j 都属于数列 C 的逆序对 （i，j）

对于（1）和（2），可以通过递归求得，对于（3）可以在归并时统计获得。

时间复杂度：
$$
O(nlogn)，其中，n为数组长度
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int a[maxn];
int b[maxn];
ll cnt;
int n;

void Merge(int s, int m, int e)
{
    int k = 0;
    int i = s;
    int j = m + 1;
    // 对于数列C中的每个数字，统计在数列B中比它大的数字的个数
    while (i <= m && j <= e)
    {
        if (a[i] <= a[j]) i ++;
        else
        {
            cnt += m - i + 1;
            j ++;
        }
    }
    i = s;
    j = m + 1;
    // 将两个有序数组合并
    while (i <= m && j <= e)
    {
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= e) b[k++] = a[j++];
    for (int i = 0; i < k; i ++) a[s+i] = b[i];
}

void MergeSortAndCount(int s, int e)
{
    if (s < e)
    {
        int m = s + (e - s) / 2;
        MergeSortAndCount(s, m);
        MergeSortAndCount(m + 1, e);
        Merge(s, m, e);
    }
}

int main()
{

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    MergeSortAndCount(0, n - 1);
    printf("%lld\n", cnt);

    return 0;
}
```



### 1.3 至少有K个重复字符的最长子串

原题链接：[至少有K个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)

分析：读完题目后似乎很难上手，但是可以发现一点：**对于一个字符串 s，如果其中某个字符的出现次数小于 k，那么最终答案一定不包含这个字符**。

于是我们可以**通过那些出现次数小于 k 的字符将字符串进行切割**，从而进行分治，即问题相同，但问题规模变小了。

对于一个字符串 s，记其符合要求的最长子串长度为 ans：

（1）开始求解 ans 的值

（2）如果 s 长度小于 k，那么 ans = 0，转向（5）

（3）统计字符串 s 中每个字符的出现次数，从左往右寻找第一个出现次数小于 k 的字符，其下标位置记为 split。如果找不到，即 split = s.size()，那么此时 s 中每个字符都至少出现了 k 次，此时 ans = s.size()，转向（5）

（4）对子串 s[0, 1, ... , split - 1] 转向（1）求解 ans 记为 left，然后从 split 开始向右找到第一个出现次数大于等于 k 的字符，其下标位置记为 split，然后对子串 s[split, split + 1, ... , s.size() -1 ] 求解 ans 记为 right，此时字符串 s 的 ans = max( left，right )

（5）求解完成。

时间复杂度：
$$
O(nlogn)，其中，n为字符串长度
$$

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        // 终止条件，如果字符串长度都小于k，那么ans=0
        int n = s.size();
        if (n < k) return 0;
		
        // 统计每个字符出现次数
        vector<int> cnt(26, 0);
        for (auto & i : s) ++cnt[i-'a'];
		
        // 找到第一个出现次数小于k的字符位置
        int split = 0;
        while (split < n && cnt[s[split]-'a'] >= k) ++split;
        // 找不到说明不用再切割了，即ans=n
        if (split == n) return n;
		
        // 对左边部分求解ans
        int left = longestSubstring(s.substr(0, split), k);
        // 继续向右找到第一个出现次数大于等于k的字符位置
        while (split < n && cnt[s[split]-'a'] < k) ++split;
        // 对右边部分求解ans
        int right = longestSubstring(s.substr(split), k);
            
        // 最终答案取左右答案中较大的
        return max(left, right);
    }
};
```



## 2. 题目指南 

### 数列上的分治法

- [逆序数](#12-逆序数)
- [至少有K个重复字符的最长子串](#13-至少有K个重复字符的最长子串)

