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