#include <bits/stdc++.h>
using namespace std;

int a[100000+10];

void arrangeRignt(int s, int e, int k)
{
    int key = a[s];
    int i = s;
    int j = e;
    while (i != j)
    {
        while (j > i && a[j] >= key) -- j;
        swap(a[i], a[j]);
        while (j > i && a[i] <= key) ++ i;
        swap(a[j], a[i]);
    }
    if (e - i + 1 == k) return;
    else if (e - i + 1 < k) arrangeRignt(s, i - 1, k - e + i - 1);
    else arrangeRignt(i + 1, e, k);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    int k;
    scanf("%d", &k);
    arrangeRignt(0, n - 1, k);
    sort(a + n - k, a + n, greater<int>());
    for (int i = n - k; i < n; i ++)
        printf("%d\n", a[i]);
    return 0;
}