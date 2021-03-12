# Zipper

原题链接：[Zipper](http://poj.org/problem?id=2192)

状态：dp [i] [j] 表示字符串 a 的前 i 个字符和字符串 b 的前 j 个字符能否构成字符串 c 的前 i + j 个字符

转移方程：dp [i] [j] = ( a[i] == c[i + j] && dp [i-1] [j] ) || ( b[j] == c[i + j] && dp [i] [j-1] )

入口：dp [i] [0] 表示字符串 a 的前 i 个字符是否能构成字符串 c 的前 i 个字符，dp [0] [i] 同理

出口：dp [n] [m] == true 表示可以构成，否则不可以

时间复杂度：
$$
O(nm)，其中，n和m表示字符串a，b的长度
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


const int maxn = 500;
int t;
char a[maxn], b[maxn], c[maxn];
bool s[maxn][maxn];

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        memset(s, 0, sizeof(s));
        scanf("%s%s%s", a+1, b+1, c+1);
        int alen = strlen(a+1);
        int blen = strlen(b+1);
        // 状态初始化
        for (int i = 1; i <= alen; ++i) 
            if (a[i] == c[i]) s[i][0] = 1;
            else break;
        for (int i = 1; i <= blen; ++i) 
            if (b[i] == c[i]) s[0][i] = 1;
            else break;
        for (int i = 1; i <= alen; ++i)
            for (int j = 1; j <= blen; ++j)
                // 状态转移
                s[i][j] = ((a[i] == c[i+j]) && s[i-1][j]) || (b[j] == c[i+j] && s[i][j-1]);
        printf("Data set %d: ", i);
        if (s[alen][blen]) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
```

