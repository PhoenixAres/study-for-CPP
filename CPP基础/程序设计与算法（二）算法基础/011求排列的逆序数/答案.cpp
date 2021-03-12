#include <bits/stdc++.h>
using namespace std;

int a[100000+10];
int b[100000+10];
long long cnt = 0;

void Merge(int s, int m, int e)
{
    int k = 0;
    int i = s;
    int j = m + 1;
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
    while (i <= m && j <= e)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= e)
        b[k++] = a[j++];
    for (int i = 0; i < k; i ++)
        a[s+i] = b[i];
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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    MergeSortAndCount(0, n - 1);
    cout << cnt << endl;
    return 0;
}