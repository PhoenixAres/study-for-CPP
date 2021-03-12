#include <bits/stdc++.h>
using namespace std;

bool IsMax(int mid, int a[], int n, int m)
{
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i ++)
    {
        if (sum + a[i] == mid)
        {
            cnt ++;
            sum = 0;
        }
        else if (sum + a[i] > mid)
        {
            cnt ++;
            sum = 0;
            i --;
        }
        else
        {
            sum += a[i];
            if (i == n - 1) cnt ++;
        }
    }
    if (cnt > m) return true;
    else return false;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n];
	for (int i = 0 ;i < n; i++) scanf("%d", a + i);
	int L = a[0];
	int R = a[0];
	for (int i = 1; i < n; i++)
    {
        if (a[i] > L) L = a[i];
        R += a[i];
    }
    while (L < R)
    {
        int mid = L + (R - L) / 2;
        if (IsMax(mid, a, n, m)) L = mid;
        else R = mid;
        if (L == mid && R == mid + 1) break;
    }
    printf("%d\n", R);
	return 0;
}