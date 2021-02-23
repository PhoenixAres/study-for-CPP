#include <bits/stdc++.h>
using namespace std;

int a[10][10];
int t[10][10];
struct Ways
{
    int x, y;
    int f;
};
Ways w[100];
stack<int> st;
int head = 0;
int tail = 0;

int main()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            scanf("%d", &a[i][j]);
    memset(t, 0, sizeof(t));
    t[0][0] = 1;
    w[head].x = 0;
    w[head].y = 0;
    w[head].f = -1;
    tail = head + 1;
    while (head != tail)
    {
        if (w[head].x == 4 && w[head].y == 4)
        {
            st.push(head);
            while (w[head].f != -1)
            {
                st.push(w[head].f);
                head = w[head].f;
            }
            while (!st.empty())
            {
                int m = st.top();
                printf("(%d, %d)\n", w[m].x, w[m].y);
                st.pop();
            }
            return 0;
        }
        else
        {
            int x = w[head].x;
            int y = w[head].y;
            if (x - 1 >= 0 && !t[x-1][y] && !a[x-1][y])
            {
                w[tail].x = x - 1;
                w[tail].y = y;
                w[tail].f = head;
                t[x-1][y] = 1;
                ++tail;
            }
            if (y - 1 >= 0 && !t[x][y-1] && !a[x][y-1])
            {
                w[tail].x = x;
                w[tail].y = y - 1;
                w[tail].f = head;
                t[x][y-1] = 1;
                ++tail;
            }
            if (x + 1 < 5 && !t[x+1][y] && !a[x+1][y])
            {
                w[tail].x = x + 1;
                w[tail].y = y;
                w[tail].f = head;
                t[x+1][y] = 1;
                ++tail;
            }
            if (y + 1 < 5 && !t[x][y+1] && !a[x][y+1])
            {
                w[tail].x = x;
                w[tail].y = y + 1;
                w[tail].f = head;
                t[x][y+1] = 1;
                ++tail;
            }
            ++head;
        }
    }
    return 0;
}