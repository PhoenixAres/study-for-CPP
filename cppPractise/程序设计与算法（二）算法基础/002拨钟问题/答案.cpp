#include <bits/stdc++.h>
using namespace std;

char t[9][10] = {"0134", "012", "1245", "036", "13457", "258", "3467", "678", "4578"};

int a[3][3], c[3][3];

bool IsOk()
{
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            if (a[i][j] != 0) return false;
    return true;
}

void Act(int n, int cnt)
{
    while (cnt --)
    {
        for (int i = 0; isdigit(t[n][i]); i ++)
        {
            int x = t[n][i] - '0';
            a[x/3][x%3] = (a[x/3][x%3] + 1) % 4;
        }
    }
}

int main()
{
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            cin >> a[i][j];
     for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            c[i][j] = a[i][j];
    int b[9];
    int d[100];
    for (b[0] = 0; b[0] < 4; b[0] ++)
        for (b[1] = 0; b[1] < 4; b[1] ++)
            for (b[2] = 0; b[2] < 4; b[2] ++)
                for (b[3] = 0; b[3] < 4; b[3] ++)
                    for (b[4] = 0; b[4] < 4; b[4] ++)
                        for (b[5] = 0; b[5] < 4; b[5] ++)
                            for (b[6] = 0; b[6] < 4; b[6] ++)
                                for (b[7] = 0; b[7] < 4; b[7] ++)
                                    for (b[8] = 0; b[8] < 4; b[8] ++)
                                    {
                                        for (int i = 0; i < 3; i ++)
                                            for (int j = 0; j < 3; j ++)
                                                a[i][j] = c[i][j];
                                        for (int i = 0; i < 9; i ++)
                                            if (b[i]) Act(i, b[i]);
                                        if (IsOk())
                                        {
                                            int k = 0;
                                            for (int i = 0; i < 9; i ++)
                                                for (int j = 0; j < b[i]; j ++)
                                                    d[k++] = i + 1;
                                            for (int i = 0; i < k; i ++)
                                            {
                                                cout << d[i];
                                                if (i < k - 1) cout << " ";
                                            }
                                            cout << endl;
                                            return 0;
                                        }
                                    }
    return 0;
}