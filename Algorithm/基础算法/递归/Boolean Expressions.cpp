#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1000 + 10;
string p, s;
int n;

bool expression_value();
bool term_value();
bool factor_value();

bool factor_value()
{
    bool result;
    char op = s[n];
    if (op == '(') ++n, result = expression_value(), ++n;
    else if (op == '!') ++n, result = !factor_value();
    else if (op == 'F') ++n, result = false;
    else if (op == 'V') ++n, result = true;
    return result;
}

bool term_value()
{
    bool result = factor_value();
    while (true)
    {
        char op = s[n];
        if (op == '&') ++n, result &= factor_value();
        else break;
    }
    return result;
}

bool expression_value()
{
    bool result = term_value();
    while (true)
    {
        char op = s[n];
        if (op == '|') ++n, result |= term_value();
        else break;
    }
    return result;
}

int main()
{
    int cnt = 1;
    while (getline(cin, p))
    {
        s.clear();
        for (int i = 0; i < p.size(); ++i)
            if (p[i] != ' ') s += p[i];
        n = 0;
        bool f = expression_value();
        printf("Expression %d: ", cnt++);
        if (f) printf("V\n");
        else printf("F\n");
    }
    return 0;
}