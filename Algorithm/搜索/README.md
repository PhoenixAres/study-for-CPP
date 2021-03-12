# 目录

[1. 深度优先搜索](#1-深度优先搜索)

[2. 宽度优先搜索](#2-宽度优先搜索)

[3. 记忆化搜索](#3-记忆化搜索)

[4. 搜索剪枝](#4-搜索剪枝)

[5. 题目指南](#5-题目指南)

# 搜索
## 1. 深度优先搜索

深度优先搜索（DFS，Depth-First Search）是搜索手段之一，它从某个状态开始，不断地转移状态直到无法转移，然后回退到前一步的状态，继续转移到其他状态，如此不断重复，直至找到最终的解。

例如求解数独，首先在某个格子内填入适当的数字，然后再继续在下一个格子内填入数字，如此继续下去。如果发现某个格子无解了，就放弃前一个格子上选择的数字，改用其他可行的数字。

例题：[Lake Counting](http://poj.org/problem?id=2386)

分析：从任意的W开始，不停地把邻接的部分用 '.' 代替，1次DFS后，与初始的这个W连接的所有W都被替换为 '.'

直至图中不再存在W时，总共进行的DFS的次数就是答案。使用递归实现DFS。

时间复杂度：
$$
O(N \times M)，其中N，M表示矩阵地图的长和宽
$$




```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
char field[110][110];
int n, m;

// 现在位置(x, y)
void dfs(int x, int y)
{
    // 将现在所在位置替换为 '.'
    field[x][y] = '.';
    // 循环遍历移动的8个方向
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (x+i >= 0 && x+i < n && y+j >= 0 && y+j < m && field[x+i][y+j] == 'W') 
            	dfs(x+i, y+j);
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (field[i][j] == 'W') 
            {
                ++ans;
                dfs(i, j);
            }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", field + i);
    
    solve();
    return 0; 
}
```
## 2. 宽度优先搜索

宽度优先搜索（BFS，Breadth-First Search）也是搜索的手段之一，与DFS不同的是，BFS总是优先搜索距离初始状态近的状态。

例题：[走出迷宫](https://ac.nowcoder.com/acm/problem/14572)

分析：经典的迷宫类问题，该题询问的是能否到达终点，如果问题变成到达终点所需的最小步数，也就是BFS中，第一次到达终点的步数（因为BFS本身求的就是最短路）。

BFS通常使用队列实现，时间复杂度：
$$
O(N \times M)，其中N，M表示矩阵地图的长和宽
$$


```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int n, m;
char s[510][510]; // 记录迷宫地图
bool t[510][510]; // 标记每个点是否被走过
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
        pair<int, int> b, e;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (s[i][j] == 'S') b.first = i, b.second = j;
                else if (s[i][j] == 'E') e.first = i, e.second = j;
        queue<pair<int, int> > q;
        q.push(b);
        bool flag = false;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (t[x][y]) continue;
            t[x][y] = 1;
            // 到达终点，也即第一次到达终点，此时也为最短路
            if (x == e.first && y == e.second) { flag = true; break; }
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > n) continue;
                if (ny < 1 || ny > m) continue;
                if (!t[nx][ny] && s[nx][ny] != '#') q.push({nx, ny});
            }

        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
```
## 3. 记忆化搜索

例题：[+1-1x2](https://atcoder.jp/contests/abc188/tasks/abc188_f)

分析：将问题转化为从 y 变为 x，可以进行 +1，−1 或 ÷2 的操作，之所以这样做，是因为转化题意之后操作更受约束，即进行了剪枝。

- 如果当前值为偶数，则只能除以 2

- 如果当前值为奇数，则只能执行加 1 或减 1 ，再除以 2

因为如果要加更多的数，完全可以在除以 2 之后再加

相比之下，你可以随时加 1 或乘 2，所以有更多的分支

考虑时间复杂度：

若 y 为偶数，只会有 y/2 一个分支

若 y 为奇数，会有 (y+1)/2 和 (y−1)/2 两个分支

而且这两个数是相邻的，设为 a，a+1

如果 a 为奇数，下一层递归会有 (a+1)/2，(a−1)/2，(a+1)/2 三个分支

如果我们采用记忆化搜索的方式，则只有两个分支

同样若 a 为偶数，下一层递归会有 a/2，a/2，(a+2)/2 三个分支

记忆化后也变为了两个分支

因为每一次都会除以 2，所以最多递归 log 层

而每一层只有两个不同的数，所以最终的状态是 log 级别的。

```cpp
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
```
## 4. 搜索剪枝

穷竭搜索会把所有可能的解都检查一遍，当解空间非常大时，复杂度也会相应变大，比如 n 个元素进行排列时的复杂度为：
$$
O(n!)
$$
这样的话，即使 n = 15 也很难较早终止，于是就需要进行剪枝。

深度优先搜索时，有时早已明确知道从当前状态无论如何转移都不会存在解，这时，不再继续搜索而是直接跳过，这一方法即为剪枝。

例题：[鸣人和佐助](http://bailian.openjudge.cn/practice/4115/)

分析：最短路问题，可以使用BFS，但如果使用DFS寻找最短路就需要剪枝。

剪枝，指如果当前状态无论如何转移都不会对答案有所贡献，于是跳过该状态。

这里简单介绍两种：可行性剪枝和最优性剪枝

可行性剪枝：本题中，如果查克拉数量为0，就不能走大蛇丸手下所在的格子

最优性剪枝：（1）如果当前没到终点，但花费时间已经超过我们所记录的最短时间，就不再搜索。

（2）创建 minL 数组，minL [x] [y] [t] 表示走到(x, y)处，且查克拉数量为 t 时的花费的最小时间。如果另有一次搜索，再次到达该状态，但花费时间大于记录过的最小时间，就不再搜索。

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
char mp[300][300]; // 记录迷宫地图
int mark[300][300]; // 标记每个点是否走过
int minL[300][300][20]; // 最优化剪枝数组，记录走到(x, y)时，且查克拉数量为 t 时的最小花费时间
int m, n, t;
int minLen; // 要求的最短时间
int tempLen; // 到目前为止所花费的时间
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    // 如果当前时间大于曾记录过的最小时间，没有必要再搜索
    if (tempLen >= minLen) return ;
    // 如果到达该状态时花费的时间比曾经到达该状态的花费时间多，没有必要再搜索
    if (tempLen >= minL[x][y][t]) return ;
    minL[x][y][t] = tempLen;
    if (mp[x][y] == '+')
    {
        minLen = min(minLen, tempLen);
        return ;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m) continue;
        if (ny < 0 || ny >= n) continue;
        if (mark[nx][ny]) continue;
        mark[nx][ny] = 1;
        if (mp[nx][ny] == '#' && t)
        {
            --t;
            ++tempLen;
            dfs(nx, ny);
            --tempLen;
            ++t;
        }
        else if (mp[nx][ny] != '#')
        {
            ++tempLen;
            dfs(nx, ny);
            --tempLen;
        }
        mark[nx][ny] = 0;
    }

}

int main()
{

    scanf("%d%d%d", &m, &n, &t);
    for (int i = 0; i < m; ++i) scanf("%s", mp[i]);
    int x, y;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (mp[i][j] == '@') x = i, y = j;

    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k <= t; ++k)
                minL[i][j][k] = (1 << 30);
    tempLen = 0;
    minLen = 1 << 30;
    mark[x][y] = 1;
    dfs(x, y);
    if (minLen < (1 << 30)) printf("%d\n", minLen);
    else printf("-1\n");
    return 0;
}
```
## 5. 题目指南
### DFS

- [Lake Counting](#1-深度优先搜索)

- [棋盘问题](docs/棋盘问题.md)

- [模拟战役](docs/模拟战役.md)

### BFS

- [走出迷宫](#2-宽度优先搜索)

- [maze](docs/maze.md)

- [Third Avenue](docs/ThirdAvenue.md)

### 记忆化搜索

- [+1-1x2](#3-记忆化搜索)

### 搜索剪枝

- [鸣人和佐助](#4-搜索剪枝)