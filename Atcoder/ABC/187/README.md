# Atcoder Beginner Contest 187

比赛链接：https://atcoder.jp/contests/abc187

比赛情况：A、B、C、D 1000分

D - Choose Me

贪心，按 2a + b 排序

E - Through Path

树的dfs序，首先注意到是无根树，不妨设根是1，然后注意到每次询问的 a，b是直

接相连的，即要么a是b的父节点，要么b是a的父节点，根据这个分类讨论，如果a

是父节点，则add[1] += x, add[b] -= x, 如果b是父节点，则add[a] += x

F - Close Group

最小团覆盖，一个经典NP难问题，但是降低了问题规模。

暴力搜索dfs，要注意剪枝，最优化剪枝

