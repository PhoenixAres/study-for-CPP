# Atcoder Beginner Contest 185

比赛链接：https://atcoder.jp/contests/abc185

比赛情况：A、B、D 700分

C - Duodecim Ferra

长为L的道路，分成12段，求所有方案数

思路1：一共需要切11刀，有L-1个位置可以切，故C(L-1, 11)

思路2：完全背包

E - Sequence Matching

记 dp[i][j] 为答案，有方程 dp[i][j]=min(dp[i−1][j],dp[i][j−1])+1，这是第一种转移，意义是删掉 i 或者 j。

若 a[i]=b[j] 则还可以从 dp[i−1][j−1] 转移，因为有 a[i],b[j] 这一对不会影响答案。若没有则还可以 dp[i−1][j−1] 意义也是不删但是 y+1。

注意初始化 dp[i][0]=i，dp[0][j]=j，dp[0][0]=0。

F - Range Xor Query

树状数组入门题，直接将加法改成异或，因为异或也满足交换律，且异或的逆运算为再做一次异或