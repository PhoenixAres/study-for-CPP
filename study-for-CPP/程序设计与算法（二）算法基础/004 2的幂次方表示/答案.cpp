#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(int n)
{
    if (n == 0) printf("2(0)");
    else if (n == 1) printf("2");
    else if (n == 2) printf("2(2)");
    else
    {
        for (int i = 30; i >= 0; --i)
            if ((n >> i) & 1)
            {
                if (i > 2)
                {
                    printf("2(");
                    dfs(i);
                    printf(")");
                }
                else dfs(i);
                if (n & ((1<<(i))-1)) printf("+");
            }
                
    }

}

int main()
{
    scanf("%d", &n);
    dfs(n);
    return 0;
}