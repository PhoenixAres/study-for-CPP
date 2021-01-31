#include <bits/stdc++.h>
using namespace std;

int x[100000+10];

bool IsMind(int d, int n, int c)
{
    int cnt = 1;
    int t = x[0];
    for (int i = 1; i < n; i ++)
    {
        if (x[i] - t >= d)
        {
            t = x[i];
            cnt ++;
        }
    }
    if (cnt < c) return true;
    else return false;
}

int main()
{
    int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i ++)
        scanf("%d", x + i);
    sort(x, x + n);
    int L = 1;
    int R = x[n-1] - x[0];
    while (L < R)
    {
        int mid = L + (R - L) / 2;
        if (IsMind(mid, n, c)) R = mid;
        else L = mid;
        if (L == mid && R == mid + 1) break;
    }
    printf("%d\n", L);
	return 0;
}