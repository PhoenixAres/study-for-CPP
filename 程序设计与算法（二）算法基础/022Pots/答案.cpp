#include <bits/stdc++.h>
using namespace std;

struct Step
{
    string s;
    int a, b;
    int steps;
    int f;
};

Step s[1000];
int t[100+10][100+10];
int head = 0;
int tail = 0;
stack<int> st;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    memset(t, 0, sizeof(t));
    s[head].s = "FILL(1)";
    s[head].a = a;
    s[head].b = 0;
    s[head].f = -1;
    s[head].steps = 1;
    ++head;
    s[head].s = "FILL(2)";
    s[head].a = 0;
    s[head].b = b;
    s[head].f = -1;
    s[head].steps = 1;
    tail = head + 1;
    head = 0;
    while (head != tail)
    {
        int va = s[head].a;
        int vb = s[head].b;
        if (va == c || vb == c)
        {
            cout << s[head].steps << endl;
            st.push(head);
            while (s[head].f != -1)
            {
                st.push(s[head].f);
                head = s[head].f;
            }
            while (!st.empty())
            {
                int id = st.top();
                cout << s[id].s << endl;
                st.pop();
            }
            return 0;
        }
        else
        {
            if (va < a && vb < b && !t[a][vb])
            {
                s[tail].s = "FILL(1)";
                s[tail].f = head;
                s[tail].a = a;
                s[tail].b = vb;
                s[tail].steps = s[head].steps + 1;
                t[a][vb] = 1;
                ++tail;
            }
            if (vb < b && va < a && !t[va][b])
            {
                s[tail].s = "FILL(2)";
                s[tail].f = head;
                s[tail].b = b;
                s[tail].a = va;
                s[tail].steps = s[head].steps + 1;
                t[va][b] = 1;
                ++tail;
            }
            if (va > 0 && vb < b)
            {
                int tb = min(b, va + vb);
                int ta = va - min(b - vb, va);
                if (!t[ta][tb])
                {
                    s[tail].s = "POUR(1,2)";
                    s[tail].f = head;
                    s[tail].a = ta;
                    s[tail].b = tb;
                    s[tail].steps = s[head].steps + 1;
                    t[ta][tb] = 1;
                    ++tail;
                }
            }
            if (vb > 0 && va < a)
            {
                int ta = min(a, va + vb);
                int tb = vb - min(a - va, vb);
                if (!t[ta][tb])
                {
                    s[tail].s = "POUR(2,1)";
                    s[tail].f = head;
                    s[tail].a = ta;
                    s[tail].b = tb;
                    s[tail].steps = s[head].steps + 1;
                    t[ta][tb] = 1;
                    ++tail;
                }
            }
            if (va > 0 && !t[0][vb])
            {
                s[tail].s = "DROP(1)";
                s[tail].f = head;
                s[tail].a = 0;
                s[tail].b = vb;
                s[tail].steps = s[head].steps + 1;
                t[0][vb] = 1;
                ++tail;
            }
            if (vb > 0 && !t[va][0])
            {
                s[tail].s = "DROP(2)";
                s[tail].f = head;
                s[tail].b = 0;
                s[tail].a = va;
                s[tail].steps = s[head].steps + 1;
                t[va][0] = 1;
                ++tail;
            }
            ++head;
        }
    }
    cout << "impossible" << endl;
    return 0;
}