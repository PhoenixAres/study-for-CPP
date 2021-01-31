#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1e5 + 10;
int a[maxn];
int b[maxn];
int n;

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