#include <bits/stdc++.h>
using namespace std;

int t[30][30];
char result[100000];
int k;

bool IsOver(int p, int q)
{
    for (int i = 0; i < p; i ++)
        for (int j = 0; j < q; j ++)
            if (t[i][j] != 1) return false;
    return true;
}

bool ways(int i, int j, int p, int q)
{
    t[i][j] = 1;
    if (i - 1 >= 0 && j - 2 >=0 && !t[i-1][j-2])
    {
        if (ways(i - 1, j - 2, p, q))
        {
            result[k++] = '1' + i - 1;
            result[k++] = 'A' + j - 2;
        }
        else t[i-1][j-2] = 0;
    }
    if (i + 1 < p && j - 2 >= 0 && !t[i+1][j-2])
    {
        if (ways(i + 1, j - 2, p, q))
        {
            result[k++] = '1' + i + 1;
            result[k++] = 'A' + j - 2;
        }
        else t[i+1][j-2] = 0;
    }
    if (i - 2 >= 0 && j - 1 >=0 && !t[i-2][j-1])
    {
        if (ways(i - 2, j - 1, p, q))
        {
            result[k++] = '1' + i - 2;
            result[k++] = 'A' + j - 1;
        }
        else t[i-2][j-1] = 0;
    }
    if (i + 2 < p && j - 1 >= 0 && !t[i+2][j-1])
    {
        if (ways(i + 2, j - 1, p, q))
        {
            result[k++] = '1' + i + 2;
            result[k++] = 'A' + j - 1;
        }
        else t[i+2][j-1] = 0;
    }
    if (i - 2 >= 0 && j + 1 < q && !t[i-2][j+1])
    {
        if (ways(i - 2, j + 1, p, q))
        {
            result[k++] = '1' + i - 2;
            result[k++] = 'A' + j + 1;
        }
        else t[i-2][j+1] = 0;
    }
    if (i + 2 < p && j + 1 < q && !t[i+2][j+1])
    {
        if (ways(i + 2, j + 1, p, q))
        {
            result[k++] = '1' + i + 2;
            result[k++] = 'A' + j + 1;
        }
        else t[i+2][j+1] = 0;
    }
    if (i - 1 >= 0 && j + 2 < q && !t[i-1][j+2])
    {
        if (ways(i - 1, j + 2, p, q))
        {
            result[k++] = '1' + i - 1;
            result[k++] = 'A' + j + 2;
        }
        else t[i-1][j+2] = 0;
    }
    if (i + 1 < p && j + 2 < q && !t[i+1][j+2])
    {
        if (ways(i + 1, j + 2, p, q))
        {
            result[k++] = '1' + i + 1;
            result[k++] = 'A' + j + 2;
        }
        else t[i+1][j+2] = 0;
    }
    if (IsOver(p, q)) return true;
    else return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        memset(t, 0, sizeof(t));
        k = 0;
        int p, q;
        scanf("%d%d", &p, &q);
        if (ways(0, 0, p, q))
        {
            result[k++] = '1';
            result[k++] = 'A';
            printf("Scenario #%d:\n", i);
            for (int j = k - 1; j >= 0; j --) printf("%c", result[j]);
            printf("\n");
        }
        else
            printf("Scenario #%d:\n%s\n", i, "impossible");
        if (i < n) printf("\n");
    }
    return 0;
}