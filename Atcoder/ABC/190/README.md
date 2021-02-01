# Atcoder Beginner Contest 190

比赛链接：https://atcoder.jp/contests/abc190

比赛情况：A、B、C 600分

D - Staircase Sequences

数学题，枚举8*N的因数

E - Magical Ornament

BFS + 状压dp

状态：f[S][i]表示状态为S时，最后一个加入序列的数为c[i]

入口：0<=i<k，f[1<<i][i] = 1

转移：f[S | (1<<j)][j] = min(f[S | (1<<j)][j], f[S][i] + dis[i][c[j]])

出口：0<=i<k，f[(1<<k)-1][i]中最小值

F - Shift and Inversions 

树状数组求逆序对的个数
